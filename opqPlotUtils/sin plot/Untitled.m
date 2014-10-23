   Fs = 4000;                   % samples per second
   dt = 1/Fs;                   % seconds per sample
   StopTime = 1;                % seconds
   t = (0:dt:StopTime-dt)';     % seconds
   Fc = 59.3;                     % hertz
   x = cos(2*pi*Fc*t);
   % Plot the signal versus time:
   figure;
   subplot(1,2,1);
   plot(t,x);
   xlabel('time (in seconds)');
   title('59.3Hz sinusoid');
   ylabel('Amplitude')
   zoom xon;
[L,KD] = size(t);
   
NFFT = 2^nextpow2(L); % Next power of 2 from length of y
Y = fft(x,NFFT)/L;
Y = abs(Y);
f = Fs/2*linspace(0,1,NFFT/2+1);
subplot(1,2,2);
f = f.';
fi = fit(f(59:64), Y(59:64),'gauss2');
subplot(1,2,2);
f = f.';
plot(f(59:64), Y(59:64),'o');
hold on;
plot(fi);
hold off;
title('Single-Sided Amplitude Spectrum')
xlabel('Frequency (Hz)')
ylabel('|FFT|')