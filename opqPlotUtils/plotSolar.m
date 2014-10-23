function [] = plotSolar(fname, color,titleN)
%PLOTSOLAR Summary of this function goes here
%   Detailed explanation goes here
numberOfXTicks = 0.5;
dat = textscan(fopen(fname),'%d64,%f,%f')
utime = dat{1};
volt = dat{2};
newTime = zeros(size(utime));

for i=1:length(utime)
    elm = utime(i);
    %mattime = double(elm - 10*60*60*1000)/86400.0/1000 + 719529.0
    mattime = double(elm - 10*60*60)/86400.0 + 719529.0
    newTime(i) = mattime;
end
h = plot(newTime,volt,color);
set(gca,'Xtick',[newTime(1):numberOfXTicks:newTime(end)]);
datetick('x','mm/dd HH:MM', 'keepticks','keeplimits');
end

title(titleN)
ylabel('Power (W)');
xData = get(h,'XData');
[newTime(1):numberOfXTicks:newTime(end)]
set(gca,'Xtick',[newTime(1):numberOfXTicks:newTime(end)]);
datetick('x','mm/dd HH:MM', 'keepticks','keeplimits');
end
