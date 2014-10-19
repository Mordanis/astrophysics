SUBROUTINE get_vals

   Implicit None
   Real*8      :: mass
   Real*8      :: h_mass
   Real*8      :: he_mass
   Real*8      :: metals_mass
   
   write(*,*) "Enter the mass of the star in solar masses"
   read(*,*) mass

   write(*,*) "Enter the percent by mass of Hydrogen"
   read(*,*) h_mass

   write(*,*) "Enter the percent by mass of Helium"
   read(*,*) he_mass

   write(*,*) "Enter the percent by mass of metals"
   read(*,*) metals_mass
END SUBROUTINE get_vals
