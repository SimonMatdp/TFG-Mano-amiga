R=11;
L=76.4422e-3;
l=12e-3; %12mm
kt=4*9.81*l; %g/mA * m/s^2 * m 
offset=(pi/4); %45 grados
n=120; %120 rpms, no n120, habrá que cambiarlo

Gs=tf([n*kt/(L*l*cos(offset))],[1 R/L])
step(Gs)