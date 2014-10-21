#include <stdio.h>

int main(int argc, char *argv[])
{
   printf("%d bytes for a long double, %d bytes for a double\n", sizeof(long double), sizeof(double));
   printf("%d bytes for an int, %d bytes for a long int\n", sizeof(int), sizeof(long int));
   printf("%d bytes for a char, %d bytes for a float\n", sizeof(char), sizeof(float));
   return 0;
}
