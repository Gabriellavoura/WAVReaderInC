#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){

    FILE *fp;
    int salto = 160;
    int buffer[480] = {0};
    int cabeca = 0, rabo = 0;
    char str[100] ={0};
    long long soma = 0;
    long long rms=0;
    int dadospreenchidos=0;

    // Open the file and verify is NULL.
    if((fp = fopen("SenLog.csv","r")) == NULL){
        printf("Error! Can't open the file.\n");
        exit(1);
    }

    while(!feof(fp)){

        //Preenche de 0 a 479:.
        fgets(str,1024,fp);
        buffer[cabeca] = atoi(str);
        dadospreenchidos++;
        if(cabeca >= (3*salto)){
            cabeca =0;
            soma =0;
        }
        //Se o buffer está cheio cabeca+1(480) = 480:
        if(dadospreenchidos >= (3*salto)){
            // Soma os quadrados dos valores de 0 á 479
            for(int i = 0; i <(3*salto); i++){
                soma += buffer[i]*buffer[i];
            }
            // divide por 480 e tira a raiz:
            soma = soma/480;
            rms = sqrt(soma);
            printf("RMS: %.llu\n", rms);
            soma=0;

            // cabeca vai para o valor do rabo 0 - 160 - 320 -480;
            cabeca = rabo;
            // incrementa rabo
            rabo += salto; //160 320 480
            //faz a leitura de 160 novos valores.
            do{
                fgets(str,1024,fp);
                buffer[cabeca] = atoi(str);
                cabeca++;
            }while(cabeca != rabo);

            for(int j =0; j < 480;j++){

                //printf("%d\n",buffer[j]);
            }

                if(rabo >= (3*salto)){
                    rabo = 0;
                }
        }
                cabeca++;

    }
    fclose(fp);
    return 1;
}
