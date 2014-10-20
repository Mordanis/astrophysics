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
<<<<<<< HEAD:solar_model.f95
!   Include 'solar_getvals.f95'
   Use solar_getvals.mod
=======
   Real*8 :: mass, h_mass, he_mass, metals_mass
   Call get_vals(mass, h_mass, he_mass, metals_mass)
>>>>>>> 19d25b6ef27aa118814d3de42a561bae1c13da3b:solar_model/main.f95


END PROGRAM solar_model
