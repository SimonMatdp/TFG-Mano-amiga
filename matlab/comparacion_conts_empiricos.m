zn = xlsread('P_ZN.xls');
plot(zn(:,1), zn(:,2)/45)
hold on;

ch = xlsread('PID_CH.xls');
plot(ch(:,1), ch(:,2)/45)
hold on;

manual = xlsread('P_manual.xls');
plot(manual(:,1), manual(:,2)/45)
hold on;

legend('ZN', 'CH', 'Manual')