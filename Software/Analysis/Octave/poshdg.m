% poshdg.m
%
% Try and plot position estimation given heading and distance
% gyro+odo, compass+odo, gps-course+odo, gps-pos
%
% makes use of move.m for calculating new lat/lon based on heading & directon
%
%          1       2      3    4    5   6   7   8   9  10    11     12
% PH = [ millis, course, lat, lon, mx, my, mz, gx, gy, gz, lrdist, rrdist ]
function poshdg(PH)
	% Time
	T = PH(:,1)/1000;
	% Distance
	D = mean(PH(:,11:12),2);
	% GPS position
	LAT=PH(:,3);
	LON=PH(:,4);
	% GPS heading
	Hgps = PH(:,2);
	G0 = Hgps(1);
	P0 = [LAT(1) LON(1)];
	GPS = move([0 0], Hgps, D);
	% Gyro
	Gz = dexpfilt(PH(:,10),0.8);
	scale = -14.49787;
	offset = -0.6;
	Hgy = fmod(cumtrapz(T, Gz/scale - offset)+G0, 360);
	GYRO = move([0 0], Hgy, D);
	%
	% Estimate heading with comp filter
	%
	a=0.98;
	He=zeros(length(T),1);
	He(1) = Hgps(1);
	A=[];
	for i=2:length(T)
		dt = T(i)-T(i-1);
		r = Gz(i)/scale - offset;
		H1 = r*dt+He(i-1);
		H2 = Hgps(i);
		if (H2-H1 > 180) 
			H2 -= 360;
		elseif (H2-H1 < -180)
			H2 += 360;
		end
		H2-H1
		He(i) = fmod(a*H1 + (1-a)*H2, 360);
	end
	E = move([0 0], He, D);
	close all;
	%
	% Plot GPS course and gyro course
	%
	figure;
	plot(T, Hgy, '.', T, Hgps, '.', T, He, '.');
	title("Position estimates", "fontsize", 22);
	xlabel("Rel Lon", "fontsize", 18);
	ylabel("Rel Lat", "fontsize", 18);
	legend("GyroHdg+Odo", "GPSCourse+Odo", "Comp+Odo");
	grid on;
	% Plot GPS Course + Odo, Gyro Hdg + Odo
	%
	figure;
	plot(GYRO(:,2), GYRO(:,1), '-', GPS(:,2), GPS(:,1), '-', E(:,2), E(:,1), '..');
	title("Position estimates", "fontsize", 22);
	xlabel("Rel Lon", "fontsize", 18);
	ylabel("Rel Lat", "fontsize", 18);
	text(0, 1e-005, "Gyro scale -14.49787");
	text(0, 2e-005, "Gyro offset -0.6");
	legend("GyroHdg+Odo", "GPSCourse+Odo", "Comp+Odo");
	grid on;
	%
	% Plot GPS reported position
	%
	%figure;
	%plot(LON, LAT, '.', GPS(:,2)+LON(1), GPS(:,1)+LAT(1), '--', GYRO(:,2)+LON(1), GYRO(:,1)+LAT(1), '-.');
	%title("Lat/Lon Plots", "fontsize", 22);
	%legend("GPS", "GPS Hdg+Odo", "Gyro Hdg+Odo");
	%xlabel("Lon", "fontsize", 18);
	%ylabel("Lat", "fontsize", 18);
	%grid on;
end

% clamps degrees to  -180 to +180
% 
function cd=clamp(d)
	if (d < -180)
		cd = d + 360;
	elseif (d > 180)
		cd = d - 360;
	else
		cd = d
	end
end
