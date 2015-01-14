Real*8 FUNCTION hydroStaticEq(r_step, density, g )
!This subroutine will compute a single step
!Of the equation of Hydrostatic Equilibrium
!Equation

   Real*8 ::r_step, density, g, p_step
   p_step = -1 * density * g * r_step
   hydroStaticEq = p_step
   Return

END FUNCTION hydroStaticEq
