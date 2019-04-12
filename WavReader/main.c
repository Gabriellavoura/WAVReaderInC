#include <stdio.h>
#include <stdlib.h>

//Defines the size of buffer short because the generated data is 16bits format short = 2 bytes.
//Size is 16khz * tempo de amostra ( 5s ) = 80000 ou 43s
short buff[688000];
int byteRead = 0;

int main(){

    int i;

    FILE *wavFile;
    // Defines the log file.
    FILE *fileLog;

    // Create and Open the Log file.
    fileLog = fopen("A5-02-16bits.csv","ab");

    //Try if file is not empty return true.
    if ((wavFile = fopen("A5a-02-16bit-16k.wav", "rb")) == NULL){
        printf("Fail!");
        exit(1);
    }

    // Start the reading in 44º byte.
    fseek(wavFile, 44, 0);

    // while remains data.
    do{
        //in each loop reads 1024 bytes.
        byteRead = fread(buff,sizeof(short),1024,wavFile);

            for(i = 0; i < 1024 ; i++){
                //printf("%i == %hhx \n",i,buff[i]);
                fprintf(fileLog,"%i\n",buff[i]);
                buff[i] = 0;
            }

        //printf("%i",byteRead);
        }while(byteRead > 0 );
    //close log file
    fclose(fileLog);
    fclose(wavFile);

    return 0;
}
