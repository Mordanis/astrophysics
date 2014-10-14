!This file will contain the Saha function in fortran
!The purpose of it is to create reusable code
!
!this function will take as arguments:
!the partition functions
!the electron pressure
!the temperature
!ionization energy
!
!this function will have the following constants
!mass of electron (kg)
!boltzmann constant (eV/K and J / K)
!planck constant (Js)
!pi

FUNCTION f_saha(zI, zII, Pe, temp, chi)
IMPLICIT NONE

    Real*8             :: zI, zII, Pe, temp, chi, f_saha

    Real*8, Parameter  :: pi = 3.1415926535d0
    Real*8, Parameter  :: me = 9.1093821545d-31
    Real*8, Parameter  :: k_j = 1.380648813d-23
    Real*8, Parameter  :: k_eV = 8.617332478d-5
    Real*8, Parameter  :: h = 6.6260695729d-34
!arguments and dummy variables used to make code cleaner
    Real*8             :: first_part, second_part, third_part

    first_part  = 2.0d0 * k_j * temp * zII / (Pe * zI)
    second_part = (2.0d0 * pi * me * k_j * temp / (h * h) ) ** 1.5
    third_part  = exp(-chi / (k_eV * temp) )

    f_saha = first_part * second_part * third_part
END FUNCTION f_saha
