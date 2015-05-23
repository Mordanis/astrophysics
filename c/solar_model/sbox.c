#include <stdio.h>
#include <math.h>

#include "constants.h"
#include "settings.h"
#include "delta_temp.c"
int main(int argc, char *argv[])
{
    float temp, density, radius, g_field, pressure, energy;
    temp = 2000;
    density = 1.0e-20;
    pressure = 1.0;
    g_field = 138;
    energy = 3.84e26;
    printf("%g\n", delta_temp(temp, density, radius, g_field, pressure, energy));
    return 0;
}
