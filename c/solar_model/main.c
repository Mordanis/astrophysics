#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "constants.h"
#include "settings.h"
#include "energy.c"
#include "delta_temp.c"
#include "HSE.c"
#include "mass_cons.c"

int main(int argc, char *argv[])
{
    //FILE * output_file;
    //output_file = fopen("solar_model", "w");
    //fprintf(output_file, "## This is a stellar model for a star with a mass of %g\n", mass);
    //fprintf(output_file, "## With X_h of %g, Y_he of %g, and X_cno of %g\n", X_h, Y_he, X_cno);

    const double mass_total = mass * sun_mass;
    double mass_interior;
    double density;
    double radius;
    double temperature;
    double r_step;
    double pressure; 
    double mean_mass = (1.0 * X_h) + (4.0 * Y_he) + (20.0 * (1.0 - X_h - Y_he));
    mean_mass = mean_mass * atomic_mass_unit;
    double pressure_exterior;   
    double luminosity_interior;
    double g_field;
    double radius_estimate;
    //int complete = 0;

/*
    This simulation will start out with initial conditions that will be changed
    ***The only boundary condition is that, when density is roughly nill, the 
    interior mass must be identically the total mass
    Simulation will start outside the star, go to center, back out, and finally back to the center
    Below are the ***Initial Conditions***
*/   
  

    mass_interior = mass_total;
    temperature = 600.0; // #SWAG
    pressure_exterior = 100000.0;
    pressure = pressure_exterior;
    density = mean_mass * pressure / (k_boltz * temperature);
    radius_estimate = pow(mass, 2/3);
    radius = sun_radius * radius_estimate;
    r_step = 100;
    g_field = G_newton * mass_interior / pow(radius, 2);

    /*                                                                          *
     *  Here we estimate the luminosity of the star using the mass-luminosity
     *  relation. The estimate will fall into one of the if's listed below
     *  depending on whether it is high, medium, or low mass.
     *                                                                          */
    if (mass < 0.43)
        luminosity_interior = 0.23 * sun_luminosity * pow(mass, 2.3);          
    else if(mass < 2.0)
        luminosity_interior = sun_luminosity * pow(mass, 4);
    else if(mass < 20.0)
        luminosity_interior = 1.5 * sun_luminosity * pow(mass, 3.5);
    else
        luminosity_interior = 3200.0 * mass;
    printf("luminosity is %g\n", luminosity_interior);

/*
    This first pass is just to get a decent estimate for the central values
    of pressure, temp, density, etc.
*/
    printf("density is %g\n", density);
    printf("mass cons returns %g\n", mass_cons(density, r_step, radius));
    //printf("HSE returns %g\n", hydrostatic_equilibrium(density, g_field, r_step));
    printf("delta temp returns %g\n", delta_temp(temperature, density, radius, g_field, pressure, luminosity_interior));
    printf("energy returns %g\n", energy(density, temperature, radius));
    printf("g = %g\n", G_newton * mass_interior / pow(radius, 2.0) );
    printf("%g is density, %g is g_field, r_step is %g\n", density, g_field, r_step);
    printf("radius is %g\n", radius);

    while(radius > 1 + r_step)
    {
        radius -= r_step;
         
        g_field = G_newton * mass_interior / pow(radius, 2.0);
        mass_interior -= mass_cons(density, r_step, radius);
        pressure += hydrostatic_equilibrium(density, g_field, r_step);
        density = mean_mass * pressure / (k_boltz * temperature);
        //printf("pressure is %g\n", pressure += hydrostatic_equilibrium(density, g_field, r_step));
        //printf("stupid test temp is %g\n", temperature);
        temperature += delta_temp(temperature, density, radius, g_field, pressure,
                                    luminosity_interior) * r_step;
        //printf("stupid test temp after deltatemp() is %g\n", temperature);
        
        luminosity_interior -= energy(density, temperature, radius) * r_step;


        /*                                                                      *
         *  In this section, we throw an error for any values that don't work
         *                                                                      */
        if(density <= 0)
        {
           printf("temperature was %g\n", temperature);
           printf("pressure was %g\n", pressure);
           printf("radius was %g\n", radius);
           printf("g was %g\n", g_field);
           printf("interior mass was %g\n", mass_interior);
           printf("density was less than zero\n");
           exit(1);
        }
        
        if(temperature <= 0 || isnan(temperature) != 0)
        {
            printf("ERROR: Temperature was an impossible value: %g\n", temperature);
            printf("pressure was %g\n", pressure);
            printf("radius was %g\n", radius);
            printf("g was %g\n", g_field);
            printf("interior mass was %g\n", mass_interior);
            printf("density was %g\n", density);
            exit(1);
        }

        if(pressure <= 0)
        {
            printf("pressure wass less than zero\n");
            printf("density was %g\n, temperature was %g\n", density, temperature);
            printf("radius was %g\n");
            exit(1);
        }
    
    }
    printf("the radius is %g\n", radius);
    printf("the central pressure is %g\n", pressure);
    printf("the central temp is %g\n", temperature);
    printf("the central density is %g\n", density);
    printf("the interior mass left over is %g\n", mass_interior);
    //fclose(output_file);
    return 0;
    
    
}
