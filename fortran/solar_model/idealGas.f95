Real*8 Function idealGasForTemp(Pressure, numDensity)
   Real*8, Parameter :: k_boltz = 1.3806488D-23
   Real*8 :: temp
   temp = numDensity * k_boltz / Pressure
   idealGasForTemp = temp

   Return
End Function idealGasForTemp

Real*8 Function idealGasForPressure(temp, numDensity)
   Real*8, Parameter :: k_boltz = 1.3806488D-23
   Real*8 :: pressure
   pressure = numDensity * k_boltz * temp
   idealGasForPressure = pressure

   Return
End Function idealGasForPressure

Real*8 Function idealGasForNumDensity(temp,pressure)
   Real*8, Parameter :: k_boltz = 1.3806488D-23
   Real*8 :: numDensity
   numDensity = pressure / (temp * k_boltz)
   idealGasForNumDensity = numDensity

   Return
End Function idealGasForNumDensity
