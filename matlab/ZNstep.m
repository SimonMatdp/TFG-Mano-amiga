
L=1; T=12.5-L;

[Gc1,Kp1]=zn(1,[k,L,T,10])
[Gc2,Kp2,Ti2]=zn(2,[k,L,T,10])
[Gc3,Kp3,Ti3,Td3]=zn(3,[k,L,T,10])

G_c1=feedback(G*Gc1,1);
G_c2=feedback(G*Gc2,1);
G_c3=feedback(G*Gc3,1);
step(G_c1,G_c2,G_c3);
legend('P','PI','PID')