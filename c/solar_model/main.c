#include <stdio.h>
#include <math.h>
#include "constants.h"
#include "settings.h"
#include "energy.c"
#include "delta_temp.c"
#include "HSE.c"
#include "mass_cons.c"

int main(int argc, char *argv[])
{
    FILE * output_file;
    output_file = fopen("solar_model", "w");
    fprintf(output_file, "## This is a stellar model for a star with a mass of %f\n", mass);
    fprintf(output_file, "## With X_h of %f, Y_he of %f, and X_cno of %f\n", X_h, Y_he, X_cno);

    const double mass_total = mass * sun_mass;
    float mass_interior;
    double density;
    double radius;
    double temperature;
    const static float r_step = 200;
    double pressure;
    float average_particle_mass = (1.0 * X_h) + (4.0 * Y_he) + (20.0 * (1.0 - X_h - Y_he));
    float pressure_to_density = average_particle_mass * m_hydrogen / k_boltz;
    float luminosity_interior;
    float g_field;

/*
    This simulation will start out with initial conditions that will be changed
    ***The only boundary condition is that, when density is roughly nill, the 
    interior mass must be identically the total mass
    Simulation will start outside the star, go to center, back out, and finally back to the center
    Below are the ***Initial Conditions***
*/   
  

    radius = 1.0e10;
    mass_interior = mass_total;
    density = 1.0e-3;
    temperature = 200;
    pressure = 0;
    g_field = G_newton * mass_interior / pow(radius, 2);
    if (mass < 0.43)
        luminosity_interior = 0.23 * sun_luminosity * pow(mass, 2.3);
    else if(mass < 2.0)
        luminosity_interior = sun_luminosity * pow(mass, 4);
    else if(mass < 20.0)
        luminosity_interior = 1.5 * sun_luminosity * pow(mass, 3.5);
    else
        luminosity_interior = 3200.0 * mass;
    printf("luminosity is %f\n", luminosity_interior);

/*
    This first pass is just to get a decent estimate for the central values
    of pressure, temp, density, etc.
*/

    printf("mass cons returns %g\n", mass_cons(density, r_step, radius));
    printf("HSE returns %g\n", hydrostatic_equilibrium(density, g_field, r_step, temperature));
    printf("delta temp returns %g\n", delta_temp(temperature, density, radius, g_field, pressure, luminosity_interior));
    printf("energy returns %g\n", energy(density, temperature, radius));
    printf("g = %f\n", G_newton * mass_interior / pow(radius, 2.0) );
    printf("%f is density, %f is g_field, r_step is %f\n", density, g_field, r_step);
    while(radius > 400)
    {
        radius -= r_step;
         
        g_field = G_newton * mass_interior / pow(radius, 2.0);
        mass_interior -= mass_cons(density, r_step, radius);

        density += hydrostatic_equilibrium(density, g_field, r_step, temperature);
        pressure = density * k_boltz * temperature / ( 2 * m_hydrogen);
        temperature += delta_temp(temperature, density, radius, g_field, pressure,
                                    luminosity_interior) * r_step;
        
        luminosity_interior -= energy(density, temperature, radius) * r_step;
        if( density > 1)
        {   fprintf(output_file
                    ,"%g\t\t%g\t\t%g\t\t%g\n", radius, pressure, density, temperature);
        }
    }
    printf("the radius is %g\n", radius);
    printf("the central pressure is %g\n", pressure);
    printf("the central temp is %g\n", temperature);
    printf("the central density is %g\n", density);
    printf("the interior mass left over is %g\n", mass_interior);
    fclose(output_file);
    return 0;
    
    
}
