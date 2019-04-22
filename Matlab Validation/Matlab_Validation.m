%Lê o arquivo
%[matlabWaveRead,FS] = audioread('A1-60seg.wav');

%Transforma de double para inteiro.
%matlabWaveRead = (matlabWaveRead*32768.0);

%Calcula o RMS com janela de 480.
%movRMS = dsp.MovingRMS(480);
%matlabRMS = movRMS(matlabWaveRead);


%Validação dos Códigos em C
subplot(2,2,1);
plot(matlabWaveRead);
title("Leitura wav do MatLab:");
hold on

subplot(2,2,2);
plot(matlabRMS);
title("Calculo RMS do MatLab, Janela = 480 sem sobreposição:");
hold on

subplot(2,2,3);
plot(minhaLeituraWav);
title("Leitura wav do meu algoritmo:");
hold on

subplot(2,2,4);
plot(MeuRMS);
title("Calculo RMS do meu algoritmo, Janela = 480 com sobreposição = 30ms:");
hold on


