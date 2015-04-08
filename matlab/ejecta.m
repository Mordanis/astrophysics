function ejecta
% This file will compute the behavior of ejecta on Mercury and Earth
%   This file assumes that the ejecta leave from the center of the crater
%   and travel at an initial velocity of 50 m/s

%   This file is written as a function to avoid side effects
%   This file does not return any values, but rather 4 plots
%       2 plots showing the trajectories of the ejecta
%       2 plots showing the distance the ejecta travels as a function of
%           ejection angle

close all

v_ejecta = 50;   % Velocity of Ejected material in m/s
y_0      = 0;    % Initial height of material in m
t_step   = .001; % time step for Euler's method simulation

y = y_0;
hold on;
for g = [9.8, 3.7]

% This is the primary loop
% This makes the file run twice, once for Mercury, once for Earth

        x_max = [];
        for theta = 5:5:85
% This loop initiates everything for each ejection angle
            vx = v_ejecta * cosd(theta);
            vy = v_ejecta * sind(theta);
            x = 0;
            y = y_0;
            
            x_list = x;
            y_list = y;

            while(y >= 0)
% This loop computes an Euler Simulation of the ballistic trajectory
                delta_x = t_step * vx;
                delta_y = t_step * vy;
                delta_vy = - g * t_step;

                x = x + delta_x;
                y = y + delta_y;
                vy = vy + delta_vy;
                x_list = [x_list, x];
                y_list = [y_list, y];
            end
            plot(x_list,y_list)
            x_max = [x_max, x];
            hold on;
        end

% This section labels the trajectory curves
        xlabel('Distance traveled from center of crater');
        ylabel('Height above surface');
        
        if g == 9.8
            title('Curves of Ejecta Trajectories on Earth');
        else
            title('Curves of Ejecta Trajectories on Mercury');
        end

% This section creates and labels the distance curves
        theta = 5:5:85;
        figure()
        plot(theta, x_max);
        xlabel('angle of ejection');
        ylabel('distance traveled');
        title('Distance Ejecta travels vs. Angle of Ejection');
        figure()

end

close 5 %This line is here to keep MATLAB from opening a blank figure
hold off

end
