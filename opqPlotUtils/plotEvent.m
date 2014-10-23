function [] = plotEvent(fname, color,titleN)
%PLOTSOLAR Summary of this function goes here
%   Detailed explanation goes here
numberOfXTicks = 0.5;
dat = textscan(fopen(fname),'%f');
volt = dat{1};
time = 1/4:1/4:4096/4;
size(time)
size(volt)
h = plot(time,volt,color);
title(titleN)
ylabel('Voltage Reading');
xlabel('Time (ms)');
end
