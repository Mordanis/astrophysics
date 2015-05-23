double delta_temp(float temp, float density, float radius, float g_field,
                    float pressure, float energy)
{
    double radiative_dt;
    double convective_dt;
    float opacity;
    float k_bf;
    float k_ff;
    float k_es;
    float k_h;
    float g_gaunt = 1;
    float Z_metals = 1 - X_h - Y_he;
    float y_ratio = 5/3;
    
    /*
        In this section the opacity will be calculated
        bit by bit.
    */

    if(density > 100)
    {    
        k_bf = 1.37545e21 * g_gaunt / t_guillotine * (1 + X_h) * density * Z_metals * pow(temp, -3.5);
        k_ff = 3.68e18 * g_gaunt * (1-Z_metals) * (1 + X_h) * density * pow(temp, -3.5);
    }
    else
    {
        k_bf = 0;
        k_ff = 0;
    }

    k_es = 0.02 * (1 + X_h);
    k_h  = 7.9e-34 * Z_metals / 0.02 * pow(density, 0.5) * pow(temp, 9);

    
    
    //printf("opacities are %f, %f, %f, and %f\n", k_bf, k_ff, k_es, k_h);
    opacity = (k_bf + k_ff + k_es + k_h) / 4;

    /*
        Now we will calculate the two methods of transfer
    */
    convective_dt = (1 - 1 / y_ratio) * temp / pressure * density * g_field;
    //printf("%g\n", convective_dt);

    radiative_dt = 3 * opacity * density * energy /
                  (64 * pi * pow(radius, 2) * sigma_sb * pow(temp, 3));
    //printf("%g\n", radiative_dt);
    

    if(convective_dt > radiative_dt)
        return convective_dt;
    else
        return radiative_dt;
}
    
