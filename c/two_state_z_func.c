#include <stdio.h>
#include <math.h>
#include "thermo_constants.h"

float z_partition(float energy1, float energy2, float temp)
{
    z = exp(energy1/ (k_boltz * temp)) + exp(energy2 / (k_boltz * temp) );
    return z;
}

int main(int argc, char *argv[])
{

    /*                                                          *
     *This section declares the variables used in this file     *
     *                                                          */
    char prompt1[] = "please enter the first energy level";
    char prompt2[] = "please enter the second energy level";

    float energy1;
    float energy2;
    float partition_function;
    float delta_z;
    float expectation_energy;
    float delta_energy;
    float heat_capacity;
    float entropy;
    float temp;
    float temp_step;
    float energy_ratio;

    FILE *output_file;

    /*                                                          *
     *This section gets the energy levels from the user         *
     *                                                          */

    printf("%s\n", prompt1);
    scanf("%f", &energy1);
    printf("%s\n", prompt2);
    scanf("%f", &energy2);

    temp_step = (energy2 - energy1)/100;
    temp = 0;

    while(k_boltz * temp < (5 * energy2 - energy 1);
            {
            energy_ratio = k_boltz * temp / energy2;
            partition_function = z_partition(energy1, energy2, temp);
            delta_z = z_partition(energy1, energy2, temp + temp_step) - partition function;
            expectation_energy = k * pow(temp,2) * delta_z / (partition_function * temp_step);
            delta_energy = k * pow(temp,2) * delta_z / (partition_function * temp_step);
            entropy = expectation_energy / temp + k_boltz * log(partition_function);
            heat_capacity = 

            }

    printf("%f\t%f\n", energy1, energy2);
    return 0;
}
