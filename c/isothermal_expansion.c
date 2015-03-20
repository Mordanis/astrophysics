#include <stdio.h>
#include <math.h>
#include "thermo_constants.h"

int main(int argc, char *argv[] )
{
    float pressure, volume, temp, num_particles;
    float vol_initial = 1.0;
    float vol_final = 2.0;
    float pressure_initial = 1e5;
    int i = 0;
    float work_total = 0;
    float delta_work;
    float delta_vol;

    temp = 300;
    delta_vol = (vol_final - vol_initial) / 2;
    num_particles = pressure_initial * vol_initial / (k_boltz * temp);
    volume = vol_initial;
    pressure = pressure_initial;
    while(volume <= vol_final)
    {
        delta_work = pressure * volume;
        work_total += delta_work;
        volume += delta_vol;
        pressure = num_particles * k_boltz * temp / volume;
    }

    printf("the total work done by the gas is %f\n", work_total);
    return 0;
}
