#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

// Define the size of window 50ms
#define window_size 480 // 30ms
#define buffer_size 2080 // 130ms = 50ms + 30ms + 50ms

int main(){

	//Definindo variaveis.
	int buffer[buffer_size]; // cria buffer com 150ms do buffer;
	int write = 0;
	int i = 0;
	int read = 0;
	int read1 =0;
	int counter_elements = 0;

	//Define variaveis referentes a leitura do arquivo e manipulacoes do mesmo.
	FILE * fp;
	char str[1024]; // vetor para armazenar os caracteres lidos como string.


	// RMs calc
	long double soma_quadrado = 0;
	long double rms = 0;

    // Open the file and verify is NULL.
    if((fp = fopen("A5a-02-16khz.csv","r")) == NULL){ // Define o nome do csv para abrir
        printf("Error! Can't open the file.\n");
        exit(1);
    }

	//devemos ler o arquivo e processar:
	while(!feof(fp)){

            fgets(str,1024,fp); //Lê o arquivo de 1024 cacacteres e armazena no vetor str.
            buffer[write] = (atoi(str) & 0xff00) / 256; // Adiciona no buffer na posição head o caractere convertido.
            write = (write + 1) % buffer_size; // faz ficar "redondo".
            counter_elements++; // Soma um na quantidade de elementos.

            //Se o buffer ta cheio.
            if(counter_elements == buffer_size){

                read1 = read;
                for(i = 0; i < window_size; i++){

                    // Faz o quadrado e soma.
                    soma_quadrado += buffer[read1]*buffer[read1];
                    read1 = (read1 + 1) % buffer_size;

                }

                // RMS dado pela raiz da soma dos quadrados sobre o tamanho da janela;
                rms = sqrt(soma_quadrado/window_size);
                printf("rms:\n %.lf\n", rms);
                soma_quadrado =0;

                //Faz a cola ficar circular, pula de 160 em 160.
                read = (read + 160) % buffer_size;

                //meu contador deve consumir mais 50ms
                counter_elements = counter_elements - 160;

            }

	}
fclose(fp);
return 0;
}



