g=9.81;
l=12e-3;
kt=0.4*g*l;
L=76.4422e-3;
R=11;
Jm=0.01;
M=0.02;
J=Jm+M*l*l;
b=0.5;
theta_0=pi/4;
P=M*g*l*cos(theta_0);
n=120;

Gs=tf([kt*n/L],[J J*R/L+b b-P P*R/L])
step(Gs)