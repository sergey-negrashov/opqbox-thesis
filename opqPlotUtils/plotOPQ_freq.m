function [t,f] = plotOPQ(fname, color,titleN)
%PLOTOPQ Summary of this function goes here
%   Detailed explanation goes here
numberOfXTicks = 10;
dat = textscan(fopen(fname),'%d64,%f,%f');
utime = dat{1};
%volt = dat{3};
freq = dat{2};
newTime = zeros(size(utime));

for i=1:length(utime)
    elm = utime(i);
    mattime = double(elm - 10*60*60*1000)/86400.0/1000 + 719529.0;
    %mattime = double(elm - 10*60*60*1000)/86400.0 + 719529.0
    newTime(i) = mattime;
end

%h = plot(newTime,volt,color);
%hold on;
h = plot(newTime,freq,color);
%hold off;
title(titleN);
ylabel('Frequency(Hz)');
xData = get(h,'XData');
set(gca,'Xtick',[newTime(1):numberOfXTicks:newTime(end)]);
datetick('x','mm/dd HH:MM', 'keepticks','keeplimits');
t = int64(newTime);
f = freq;
end
