#include <stdio.h>
#include <math.h>
#include "thermo_constants.h"

long double z_partition(long double energy1, long double energy2, long double temp);


int main(int argc, char *argv[])
{

    /*                                                          *
     *This section declares the variables used in this file     *
     *                                                          */
    char prompt1[] = "please enter the first energy level";
    char prompt2[] = "please enter the second energy level";

    long double energy1;
    long double energy2;
    long double partition_function;
    long double delta_z;
    long double expectation_energy;
    long double delta_energy;
    long double heat_capacity;
    long double entropy;
    long double temp;
    long double temp_step;
    long double energy_ratio;

    FILE *output_file = fopen("partition_func.dat", "w");

    /*                                                          *
     *This section gets the energy levels from the user         *
     *                                                          */

    printf("%s\n", prompt1);
    scanf("%Lf", &energy1);
    printf("%s\n", prompt2);
    scanf("%Lf", &energy2);

    temp_step = (energy2 - energy1)/100;
    temp = temp_step;

    fprintf(output_file, "%s\n", "Z    <E>  S    C");
    //printf("%f\t%f\n", k_boltz * temp, 5 * (energy2 - energy1));
    while(temp < 500 * temp_step)
            {
            energy_ratio = k_boltz * temp / energy2;
            partition_function = z_partition(energy1, energy2, temp);
            delta_z = z_partition(energy1, energy2, temp + temp_step) - partition_function;
            expectation_energy = k_boltz * pow(temp,2) * delta_z / (partition_function * temp_step);
            delta_energy = k_boltz * pow(temp,2) * delta_z / (partition_function * temp_step);
            entropy = expectation_energy / temp + k_boltz * log(partition_function);
            heat_capacity = delta_energy / temp_step;

            fprintf(output_file, "%Lf    %Lf    %Lf    %Lf    %Lf\n", 
                    partition_function, expectation_energy, entropy, heat_capacity);

            temp += temp_step;        
            //printf("%f\t%f\n", k_boltz * temp, 5 * (energy2 - energy1)); 
            }
    fprintf(output_file, "End of File");
    return 0;
    fclose(output_file);
}

long double z_partition(long double energy1, long double energy2, long double temp)
{
    long double z;
    z = exp(energy1/ (k_boltz * temp)) + exp(energy2 / (k_boltz * temp) );
    return z;
}

