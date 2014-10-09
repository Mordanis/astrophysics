!this file will contain various physical constants
!And will be able to be used for most programs written in
!this directory 
! *** Every variable will have a _units tag at the end ***
! unless there is only one set of units associated with the constant
! this will be less efficient while typing code, but not
! having to include every physical parameter every time is worth it
SUBROUTINE CONSTANTS
IMPLICIT NONE

Real*8, Parameter :: Mass_Sun          = 1.9891d30
Real*8, Parameter :: Irradiance_Sun    = 1.3652d3
Real*8, Parameter :: Luminosity_Sun    = 3.8395d26
Real*8, Parameter :: Radius_Sun        = 6.9550826d8
Real*8, Parameter :: T_eff_Sun         = 5777.2d0
Real*8, Parameter :: Mass_Earth        = 5.9736d24
Real*8, Parameter :: Radius_Earth      = 6.378136d6
Real*8, Parameter :: AU_to_m           = 1.4959787066d11
Integer, Parameter:: seconds_in_day    = 86400
Integer, Parameter:: julian_year       = seconds_in_day * 365.25
Integer, Parameter:: speed_of_light    = 299792458
Integer, Parameter:: ly_to_m           = speed_of_light * sec_in_jul_year
Real*8, Parameter :: sidereal_year     = 3.15581450d7
Real*8, Parameter :: tropical_year     = 3.155692519d7
Real*8, Parameter :: gregorian_year    = 3.1556952d7
Real*8, Parameter :: big_G             = 6.6742867d-11
Real*8, Parameter :: pi                = 3.14159265358979323846264338327950288419716939937510582
Real*8, Parameter :: mu_0              = 4 * pi * 1d-7
Real*8, Parameter :: epsilon_0         = 1 / mu_0 / c / c
Real*8, Parameter :: electron_charge   = 1.60217648740d-19
Real*8, Parameter :: eV_to_J           = electron_charge
Real*8, Parameter :: h_planck          = 6.6260689633d-34
Real*8, Parameter :: h_bar             = planck_h / 2 / pi
Real*8, Parameter :: k_boltz           = 1.380650424d-23
Real*8, Parameter :: stefan_boltz      = 2 * pi**5 * k_boltz**4 / (15 * speed_of_light**2 * h_planck**3)
Real*8, Parameter :: rad_constant      = 4 * stefan_boltz / speed_of_light
Real*8, Parameter :: atomic_mass_unit  = 1.66053878283d-27
Real*8, Parameter :: mass_electron     = 9.1093821545d-31
Real*8, Parameter :: mass_proton       = 1.67262163783d-27
Real*8, Parameter :: mass_neutron      = 1.6749271184d-27
Real*8, Parameter :: mass_hydrogen     = 1.67353249913d-27
Real*8, Parameter :: avogadro          = 6.0221417930d23
Real*8, Parameter :: gas_constant      = 8.331447215d0
Real*8, Parameter :: radius_bohr       = 4 * pi * epsilon_0 * h_bar**2 / (mass_electron * electron_charge**2)
Real*8, Parameter :: rydberg_constant  =mass_electron * electric_charge**4 /(64 * pi**3 * epsilon_0**2 * h_bar**3 * speed_of_light)

END SUBROUTINE CONSTANTS
