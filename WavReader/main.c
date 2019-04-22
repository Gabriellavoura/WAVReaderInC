#include <stdio.h>
#include <stdlib.h>

//Defines the size of buffer short because the generated data is 16bits format short = 2 bytes.
//Size is 192khz * sample time ( 60s ) = 11520000
short buff[11520000];
int byteRead = 0;

int main(){

    int i;

    FILE *wavFile;
    // Defines the log file.
    FILE *fileLog;

    // Create and Open the Log file.
    fileLog = fopen("A1-60seg.csv","ab");

    //Try if file is not empty return true.
    if ((wavFile = fopen("A1-60seg.wav", "rb")) == NULL){
        printf("Fail!");
        exit(1);
    }

    // Start the reading in 44º byte ( end of wave head file).
    fseek(wavFile, 44, 0);

    // while remains data.
    do{
        //If you need float-pointer ( for MatLab comparison purposes) use this:
        //byteRead = (fread(buff, sizeof(short), 1, wavFile))/32768.0;

        //in each loop reads 1 byte
        byteRead = fread(buff,sizeof(short),1,wavFile);

            for(i = 0; i < 1 ; i++){
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
