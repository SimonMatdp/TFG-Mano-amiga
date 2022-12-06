k=0.24487;
Tp1=0.078965;
Tp2=0.079019;

N=4;

s=tf('s');
G=tf(k, [Tp1*Tp2 Tp1+Tp2 1])
[yG, tG]=step(G);

%---

first_d=gradient(yG)./gradient(tG);
second_d=gradient(first_d)./gradient(tG); %22-23 -> 0.0535-0.0576

muestra_tangente=23;
m=(yG(muestra_tangente)-yG(muestra_tangente-1))/(tG(muestra_tangente)-tG(muestra_tangente-1))
x= linspace(0,0.26,1000);
tangente= m*(x-tG(muestra_tangente-1))+yG(muestra_tangente-1); %muestra_tangente-1

% plot(x, tangente)
% hold on;
% yline(0.2445) % x=0.2366
% hold on;
% yline(0) %x=0.0222
% %hold on;
% %plot(t ,y_150(:,1))
% hold on;
% step(G)

%---

L=0.0222; 
T=0.2144;

[Gc1,Kp,Ti,Td]= chreswickpid (2,1,[k,L,T,N,0]) % PID, no carga, 

figure
hold on;
step(feedback(G*Gc1,1))
