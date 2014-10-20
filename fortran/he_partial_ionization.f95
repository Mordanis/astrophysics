INCLUDE 'f_saha.f95'
!this program will create a data file that will be used
!to plot the ionization states of He vs. temperature
!this program uses a function, f_saha, defined in another
!file that finds the ratio of ionization states
PROGRAM partial_ionization
IMPLICIT NONE
 
    Real*8            :: f_saha
    
    Real*8, Parameter :: zI     = 1
    Real*8, Parameter :: zII    = 2
    Real*8, Parameter :: zIII   = 3
    Real*8, Parameter :: Pe     = 1.0d3
    Real*8, Parameter :: chi_I  = 24.6
    Real*8, Parameter :: chi_II = 54.4

    Integer, Parameter :: highest_t = 55000
    Real*8, Dimension(1:highest_t) :: temp

    Real*8 :: ratio_3_2
    Real*8 :: ratio_2_1
    Real*8, Dimension(1:highest_t) :: ratio_3_1
    Real*8, Dimension(1:highest_t) :: ratio_2_all
    Real*8, Dimension(1:highest_t) :: ratio_1_all


    Integer :: i = 1
    Integer :: out_unit = 20
    open(unit=out_unit,file='partial_ionization.dat',action='write',status='replace')
    write(out_unit,*) "#Temperature     % of HeIII         % of HeII         % of HeI"

    do while(i < highest_t)
        temp(i) = i + 5000
        ratio_3_2 = f_saha(zII,zIII,Pe,temp(i),chi_II)
        ratio_2_1 = f_saha(zI,zII,Pe,temp(i),chi_I)
        ratio_3_1(i) = 1 / (1 + (1 / ratio_3_2) + (1/(ratio_3_2 * ratio_2_1)))
        ratio_2_all(i) = 1 / (1 + (1/ratio_2_1) + ratio_3_2)
        ratio_1_all(i) = 1 / (1 + ratio_2_1 + ratio_3_2 / ratio_2_1)
        write(out_unit,*) temp(i), "    ", ratio_3_1(i), "    ", ratio_2_all(i), "    ", ratio_1_all(i)
        i = i + 1
    end do

END PROGRAM partial_ionization
