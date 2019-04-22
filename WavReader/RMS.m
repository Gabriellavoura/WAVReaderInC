%H = blackmanharris(length(rm));
%hfft = hamming(length(H));
%a = fft(hfft).*rm;
%original_rms = rms(original);
%subplot(2,1,1);
plot(varOriginal)
title('RMS')
%hold on
%subplot(2,1,2);
%plot(abs(rm_gigante))%
%hold on
%title('wav pós RMS')