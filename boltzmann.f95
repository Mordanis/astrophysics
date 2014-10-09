!This Program will calculate the Boltzmann equation
!Tomorrow at the earliest
!Please
!Again, I'd like to modify this to eventually be a function
!But it will be a program until I figure that out

!(c) John Van Dyke, 2014
!all units are mks unless a _other_unit comes after the variable

PROGRAM boltzmann

!First we'll define the constant
    Real*8, Parameter :: k_eV = 8.61734315d-5

!Now we'll define the variables we'll ask the user for and a variable for the answer
    Integer :: states_b
    Integer :: states_a
    Real*8  :: energy_b
    Real*8  :: energy_a
    Real*8  :: temp
    Real*8  :: ratio

! Now we'll get the values for these variables
    
    write(*,*) "How many degenerate states are there for b?"
    read(*,*) states_b

    write(*,*) "How many degenerate states are there for a?"
    read(*,*) states_a

    write(*,*) "what is the energy of state b in eV?"
    read(*,*) energy_b

    write(*,*) "what is the energy of state a in eV?"
    read(*,*) energy_a

    write(*,*) "what is the temperature"
    read(*,*) temp

    ratio = EXP((energy_a - energy_b) / ( k_eV * temp))
    ratio = ratio * states_b
    ratio = ratio / states_a

    write(*,*) "the ratio of things in state b to state a is ", ratio

END PROGRAM boltzmann
