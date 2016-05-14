double delta_temp(double temp, double density, double radius, double mass_interior,
                    double pressure, double energy)
{
    
    double g_field;
    double radiative_dt;
    double convective_dt;
    double opacity;
    double k_bf;
    double k_ff;
    double k_es;
    double k_h;
    double g_gaunt = 1;
    double Z_metals = 1 - X_h - Y_he;
    double y_ratio = 5/3;
    double dt;
    

    double epsilon;
    double epsilon_pp;
    double epsilon_cno;
    double epsilon_3a;
    

    g_field = G_newton * mass_interior / power(radius,2);
    /*			Temperature Gradient Section			*
     *	We shall calculate opacities bit by bit				*
     *	Then calculate the temperature gradient via convection and	*
     *	radiation. Only the more efficient method will be used to 	*
     *	calculate dt/dr							*
     *									*/

    k_bf = 1.37545e21 * g_gaunt / t_guillotine * (1 + X_h) * density * Z_metals * pow(temp, -3.5);
    k_ff = 3.68e18 * g_gaunt * (1-Z_metals) * (1 + X_h) * density * pow(temp, -3.5);

    k_es = 0.02 * (1 + X_h);
    if(temp < 1e4)
        k_h  = 7.9e-34 * Z_metals / 0.02 * pow(density, 0.5) * pow(temp, 9);
    else
        k_h = 0;

    
    
    //printf("opacities are %f, %f, %f, and %f\n", k_bf, k_ff, k_es, k_h);
    opacity = (k_bf + k_ff + k_es + k_h) / 4;
    //printf("opacity is %f\n", opacity);

    /*									*
     * Now we will calculate the two methods of transfer		*
     *									*/
    convective_dt = ((y_ratio - 1/ y_ratio)) * temp / pressure * density * g_field;
    //printf("the  convective delta t is %f\n", convective_dt);

    radiative_dt = 3 * opacity * density * energy /
                  (64 * pi * pow(radius, 2) * sigma_sb * pow(temp, 3));
    //printf("%the radiative delta t is %f\n", radiative_dt);
    

    if(convective_dt > radiative_dt )
        dt = convective_dt;
    else
        dt = radiative_dt;

    return dt;

    //printf("dt is %f\n", dt);
}









    /*		Energy Generation Section				*		
     *									*
     *									*
     *	If the temperature is less than 5 million Kelvin		*
     *	There is no energy generation occuring, so I'll save		*	
     *	some CPU cycles by not computing dl/dt below that temp		*
     *									*/
double energy_gen(temperature, density)
{

    double epsilon;

    if (temperatue < 5e6)
	    epsilon = 0;
    else
    {
	double T6 = temperature * 1e-6;
	double T8 = temperature * 1e-8;
	double epsilon_pp = 0.244 * density * pow(x_hydrogen,2) * pow(T6, -2/3) * exp(-33.8 * pow(T6, -1/3));
	double epsilon_cno = 8.67e20 * density * x_hydrogen * x_cno * pow(T6, -2/3)  exp(-152.28 * pow(T6, -1/3));
	double epsilon_3a = 50.9 * pow(density, 2) * pow(y_helium,3) * pow(T8, -3) * exp(-44.027 / T8);

	epsilon = epsilon_pp + epsilon_cno + epsilon_3a;
    }
    return epsilon;
}


double d_luminoisity(epsilon, density, radius, r_step)
{
	double d_luminosity = 4 * pi * pow(radius, 2) * density * r_step * epsilon;
	return d_luminosity;
}







    /*		Hydrostatic Equlibrium					*
     *	Standard expression with a few extra terms to account for	*
     *	The change in temperature as we go in as well as the exra	*
     *	mass above							*
     *	dp = rho*g*dr - 4sigma/c * [4T^3dt + 6T^2dt^2 + 4Tdt^3 + dt^4]  */
double HSE(density, g_field, dr, temp, dt)
{

    d_pressure = density * g_field * dr + 4 * sigma_sb / c_light * (4 * pow(temp, 3) * dt +
		    						    6 * pow(temp, 2) * dt * dt +
							  	    4 * temp * pow(temp,3) +
								    pow(temp, 4) 		);
    
    return d_pressure;
}


    /*		Mass Conservation					*
     * Very Simple, the change in mass_interior is equal to the mass	*
     * of the current shell.						*
     * 									*/
double mass_cons(radius, d_r, density)
{
    d_mass = 4 * pi * pow(radius, 2) * d_r * density;
    return d_mass;
}
    /*		Calculating values and returning them			*
     *									*/

    double new_density = average_mass * mass_hydrogen / (k_boltz * temp) * (pressure - 4/3 * sigma_sb/c_light * pow(temp,4));
    double d_density = 

}
    
