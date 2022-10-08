  clear;
  clc;
  
a = arduino('COM3');
   writeDigitalPin(a, 'D13', 0);
   pause(2);
   writeDigitalPin(a, 'D13', 1);
   
  while 1
%       writeDigitalPin(a, 'D13', 1);
%       pause(0.5);
%       writeDigitalPin(a, 'D13', 0);
%       pause(0.5);
      
      voltage = readVoltage(a, 'A0')
      pause(0.001); %1ms
   end
   