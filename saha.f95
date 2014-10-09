!This will initially be a program
!Eventually I hope to make it simply a function
!that will calculate the ratio of two ionization
!states given
!
!ionization energy
!partition functions
!Temperature
!electron pressure

Include 'f_saha.f95'

PROGRAM saha

!we'll define and get the values
!for the right hand side of the equation

    Real*8 :: chi
    Real*8 :: zI
    Real*8 :: zII
    Real*8 :: Pe
    Real*8 :: temp
    Real*8 :: ratio

    write(*,*) "Please enter the ionization energy in eV"
    read(*,*) chi
    !write(*,*)  'The ionization energy is ', chi **** Line included for debugging
    write(*,*) "Please enter the first partition function"
    read(*,*) zI

    write(*,*) "Please enter the second partition function"
    read(*,*) zII

    write(*,*) "Please enter the electron pressure in N/m^2"
    read(*,*) Pe

    write(*,*) "Please enter the temperature in Kelvin"
    read(*,*) temp

!Finally, we'll solve the dern thing
    
    ratio = f_saha(zI, zII, Pe,temp, chi)

    write(*,*) "The ratio is ", ratio

END PROGRAM saha
