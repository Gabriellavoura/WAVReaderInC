[Sile2] = audioread('seno.wav');

%Transforma de double para inteiro.
%SenLog = (SenLog/32768.0);

%Dados extraídos do meu código.
subplot(2, 1, 1);
plot(SenLog);
title('Meu código');

%Dados lidos pela função do matlab.
subplot(2, 1, 2);
plot(Sile2);
title('Gerado pelo MATLAB');
