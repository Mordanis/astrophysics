!FILLER COMMENT BEFORE FILE IS MADE

Real*8 Function massConservation(rho,radius)
   Real*8 :: dm
   Real*8, Parameter :: pi = 3.1415926535897932384626433832795028841971
   dm = 4 * pi * rho * radius * radius
   massConservation = dm

   return
   End Function massConservation
