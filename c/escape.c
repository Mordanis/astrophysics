#include <stdio.h>
#include <math.h>


/*
These are the Physical Constants used in this simulation
M_Earth and R_Earth actually just refer the mass of the 
large body, either Earth or the Moon
*/
#define G               6.67626e-11
#define M_Earth          7.342e22
#define R_Earth          1738.1e3
#define k_boltz         1.380648813e-23
#define pi              M_PI
#define amu             1.66053892e-27


int main(int argc, char *argv[])
{
    /*
        Open and initialize the file 
        the file will be used by gnuplot to plot the
        velocity distribution
    */
    FILE *output_file;
    output_file = fopen("escape.dat","w");
    fprintf(output_file, "##velocity\t\tprobability\t\tcumulative probability\n");

    /*
        Declaring all of the variables used
        floats are used because this is designed to run on a VM,
        so performace is an issue
    */
    float probability;
    float probability_slice;    
    float escape_probability = 0;
    float v_esc;
    float width = .5; // in m/s, width of "dv"
    float mass; 
    float velocity;
    float temp = 1000;

    /*
        calculate the escape velocity and mass of the particle in kg
    */
    v_esc = sqrt(2 * G * M_Earth / (R_Earth + 1000e3));
    mass = 4.002 * amu;
    fprintf(output_file, "## escape velocity is %f\n m/s", v_esc);
    
    /*
        Initial conditions to start the Euler's Method simulation
    */
    probability = 0;
    velocity = 0;
    while(probability < 0.9999)
    {
    /*
        In this loop, f(v) is calculated
        the total probability is found by adding the
        total probability so far to f(v) * dv

        dv is the width, 1/2 m/s 
    */
        probability_slice = pow(mass / (2 * pi * k_boltz * temp), 1.5);
        probability_slice *= (4 * pi * velocity * velocity);
        probability_slice *= exp(- mass * velocity * velocity / (2 * k_boltz * temp));
        probability += probability_slice * width;
        velocity += width;
        fprintf(output_file, "%f\t\t%f\t\t%f\n", velocity, probability_slice, probability);

        if( velocity > v_esc )
            escape_probability += (probability_slice * width);
    } 


    /*
        Here we simply close the file and output the information we need to the terminal
    */
    fclose(output_file);
    printf("escape velocity is %f m/s\n", v_esc);
    printf("99.99 per cent of all h2 are traveling below %f m/s\n", velocity);
    printf("The probability of escape is %f\n", escape_probability);
    return 0;
}
