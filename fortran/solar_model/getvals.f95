SUBROUTINE get_vals(mass, h_mass, he_mass, metals_mass)
!This subroutine just asks the user for the mass and 
!Composition of the star to be modeled. As of 10-19-2014
!This subroutine is considered to be in working, bugless
!order. The only potential problems I can imagine coming
!are from improper use(negative values, the mass pcts 
!not adding up to 1, etc)
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

   metals_mass = 1 - h_mass - he_mass
END SUBROUTINE get_vals
