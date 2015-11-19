[voltage, time] = textread('data.txt','%12.6f%12.8f','delimiter',' ');
plot(time, voltage)