double hydrostatic_equilibrium(float density, float g_field, float delta_r, float temp)
{
    double delta_density;
    delta_density = 2 * density * g_field * delta_r * m_hydrogen / (k_boltz * temp);
    return delta_density;
}
