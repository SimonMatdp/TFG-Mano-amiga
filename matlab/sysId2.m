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

[Gc1,Kp1,Ti1,Td1]= chreswickpid (1,1,[k,L,T,N,0]) % PID, no carga,
[Gc2,Kp2,Ti2,Td2]= chreswickpid (2,1,[k,L,T,N,0]) % PID, no carga,
[Gc3,Kp3,Ti3,Td3]= chreswickpid (3,1,[k,L,T,N,0]) % PID, no carga, 

figure
hold on
step(feedback(G*Gc1,1))
hold on
step(feedback(G*Gc2,1))
hold on
step(feedback(G*Gc3,1))
hold on
stepresponse = xlsread('PID_CH.xls');
plot(stepresponse(:,1), stepresponse(:,2)/45)
hold on;
step(G)

legend('P', 'PI', 'PID', 'PID real')