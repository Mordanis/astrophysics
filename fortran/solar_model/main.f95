!This program will model the interior of a star
!It will prompt the user for the mass
!and composition of the star -- star will be
!modeled as a zero age main sequence

!This file will only call other files
!My goal is to make this model as quick
!as the one included in Carrol & Ostlie

Include 'getvals.f95'
Include 'hydroStaticEq.f95'
Include 'idealGas.f95'
Include 'mass_cons.f95'


PROGRAM solar_model

   Implicit None

   Real*8 :: mass, h_mass, he_mass, metals_mass
   Call get_vals(mass, h_mass, he_mass, metals_mass)

   write(*,*) mass, h_mass, he_mass, metals_mass

END PROGRAM solar_model
