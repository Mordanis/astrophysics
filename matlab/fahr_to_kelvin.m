function [kelvin_array] = fahr_to_kelvin(fahr_array)

   abs_zero_fahr = -459.67;

   kelvin_array = (fahr_array + abs_zero_fahr) * 5/9;

   end

function S_and_M_hw1()
   
   abs_zero_fahr = -459.67;
   room_temp_fahr = 70;

   prompt = 'please enter a temperature in faherenheit to be converted to kelvin';
   fahr_array = input(prompt);
   if fahr_array == []
      fahr_array = [abs_zero_fahr, room_temp_fahr];
      end

   kelvin_array = fahr_to_kelvin(fahr_array);

   printed_array = [fahr_array;kelvin_array]
   
   end
