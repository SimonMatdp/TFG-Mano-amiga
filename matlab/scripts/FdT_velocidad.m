R=11;
L=76.4422e-3;
l=12e-3; %12mm
g=9.81;
kt=4*g*l; %4g/mA * g * l
theta_0=pi/4; %45 grados
n=120;
k=n*L*kt;
Jm=0.01;
bm=0.01;
Jp=0.5;
bp=0.5*6;
M=0.02; % 20g
Py=M*g*l*cos(theta_0);


Gs=tf([k*Jm k*bm 0],[Jp bp+n*n*R/L+n*n+Jp*R/L bp*R/L+Py Py*R/L])
step(Gs)