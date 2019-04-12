xdel(winsid());
clear;
//Leitura dos arquivos WAV
[y,Fs,bits]=wavread("seno");
y = (y*32768.0);    

t=0:1/Fs:(length(y)-1)/Fs

janela=(30e-3)*Fs
avanca=(10e-3)*Fs
inicio=0
fim=0
evento=0
passagem=0
deteccao=[1,1,1]

silencio=(100e-3)
tempo=(50e-3)*Fs
for amostra=1:avanca:length(y)
        if (amostra+janela)>length(y)
            fim_janela=(length(y) - 1)
        else
            fim_janela=amostra+janela
        end
        valor=sqrt(sum(y(amostra:fim_janela)^2))
        rms(1,amostra:fim_janela)=sqrt((sum(y(amostra:fim_janela)^2))/480)
       
        if((silencio+fim)<t(amostra))
            if((valor>=0.2)&(evento==0))
                if(amostra-tempo>0)
                    inicio=t(amostra-tempo)
                    evento=1
                else
                    inicio=t(amostra)
                    evento=1
                end
            else
                if((valor<0.2)&(evento==1))
                    if(amostra+tempo<=length(y))
                        fim=t(amostra+tempo)    
                    else
                        fim=t(amostra)
                    end        
                    evento=0
                    passagem=1+passagem;
                    deteccao(passagem,:)=[inicio,fim,fim-inicio]
                    end
            end              
        end
end

