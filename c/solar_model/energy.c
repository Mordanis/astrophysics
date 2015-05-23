double energy (float density, float temp, float radius)
{
    float energy_per_mass;
    double energy_total;
    float energy_pp;
    float energy_cno;
    float energy_3a;
    
    float t6 = temp / 1e6;
    float t8 = temp / 1e8;

    energy_pp = 0.241 * density * pow(X_h, 2) //continued below
                * pow(temp, (2/3) ) * exp(-33.8 * pow(t6, (-1/3) ));
    
    energy_cno = 8.67e20 * density * X_h * X_cno //continued below
                 * pow(t6, (-2/3) ) * exp(-152.28 * pow(t6, (-1/3) ));

    energy_3a = 50.9 * pow(density, 2) * pow(Y_he, 3) * pow(t8, -3) //below
                * exp(-44.027 / t8);

    energy_per_mass = energy_pp + energy_cno + energy_3a;
    energy_total = 4 * pi * pow(radius, 2) * density * energy_per_mass;
    return energy_total; 
}
