#include <stdio.h>
#include <math.h>


/*                                                 *
 *  Written by John Van Dyke                       *
 *  Fall 2014                                      *
 *  This program will calculate the partial        *
 *  ionization zone for hydrogen                   *
 *  Units are mks unless specified otherwise       *
 *                                                 */
int main(int argc, char *argv[])
{
   // Open file to hold results
   FILE *output_file;
   output_file = fopen("partial_ionization.dat", "w");


   // Variables for temperature array
   const int num_steps = 1e4;
   const int min_temp = 5e3;
   int temp[num_steps]; //10,000 K to 20,000 K
   int i = 0;

   // Physical constants
   const double h_planck = 6.6260689633e-34;
   const double k_eV    = 8.61734315e-5;
   const double k_boltz  = 1.380650424e-23;
   const int    c_light  = 299792458;
   const double m_electron = 9.1093821545e-31;
   const double pi       = 3.1415926535897932384626433832795028841971693993751;

   // Variables for calculating the ratio
   double ratio_2_1[num_steps];
   double first_part;
   double second_part;
   double third_part;

   // Variables to get from the user
   float chi;
   float Z_I;
   float Z_II;
   float p_e;
   
   // Get the values from the user
   printf("%s", "Please enter the ionization energy in eV\n");
   scanf("%f", &chi);

   printf("%s", "Please enter the first partition function\n");
   scanf("%f", &Z_I);

   printf("%s", "Please enter the second partition function\n");
   scanf("%f", &Z_II);

   printf("%s", "Please enter the electron pressure in N/m^2\n");
   scanf("%f", &p_e);
   printf("%f", p_e);


   // Loop over indices

   while(i < num_steps)
   {
      temp[i] = min_temp + i;
      first_part = 2 * k_boltz * temp[i] * Z_II / (p_e * Z_I);
      second_part = pow(2 * pi * m_electron * k_boltz * temp[i] / (h_planck * h_planck) , 1.5);
      third_part = exp(-chi / (k_eV * temp[i]));
      ratio_2_1[i] = first_part * second_part * third_part;
      fprintf(output_file, "%d\t\t%lf\n", temp[i], ratio_2_1[i]);
      i++;
   }

   return 0;

}
