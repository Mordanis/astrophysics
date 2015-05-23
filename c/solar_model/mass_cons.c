double mass_cons(double density, double delta_r, double radius)
{
    double delta_m;
    delta_m = 4 * pi * pow(radius, 2) * density * delta_r;
    return delta_m;
}
