g=9.81;
l=12e-3;
kt=0.4*g*l;
L=76.4422e-3;
R=11;
M=0.02;
Jm=0.1;
J=Jm+M*l*l;
b=0.5;
theta_0=pi/4;
P=M*g*l*cos(theta_0);
n=120;

s=tf('s');

Gs=feedback(1/(R+L*s) * kt*n * 1/(J*s*s + b*s + P), n*s/kt)
%Gs=tf([kt*n/L],[J J*R/L+b b*R/L+P+n*n/L P*R/L])
%step(Gs,2e6)

%Un polo dominante, y por mucho
hold on
Gsimp=tf([kt*n/L],[b*R/L+P+n*n/L P*R/L])
%step(Gsimp,2e6)

%Despreciando efecto del peso
hold on
Gsimp2=feedback(1/(R+L*s) * kt*n * 1/(J*s*s + b*s), n*s/kt)
step(Gsimp2,2e6)

%legend('Planta','Aproximación por polo dominante', 'Despreciando efecto de la masa')

%recta real
figure
stepresponseopenloop = xlsread('../stepResponseOpenLoop.xls');
plot(stepresponseopenloop(:,1), stepresponseopenloop(:,2)/150)
legend('Real')

%Ñapa realimentando
figure()
Nyapa=feedback(Gsimp, 1)
step(Nyapa)
legend('Realimentacion unitaria')