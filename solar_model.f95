!This program will model the interior of a star
!It will prompt the user for the mass
!and composition of the star -- star will be
!modeled as a zero age main sequence

!This file will only call other files
!My goal is to make this model as quick
!as the one included in Carrol & Ostlie

Include 'solar_getvals.mod'
PROGRAM solar_model

   Implicit None
!   Include 'solar_getvals.f95'
   Use solar_getvals.mod


   Call get_vals

END PROGRAM solar_model
