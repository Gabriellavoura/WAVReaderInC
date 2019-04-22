// File for testing some functionalities

#include <stdio.h>
#include <stdlib.h>

//Defines the size of buffer short because the generated data is 16bits format short = 2 bytes.
//Size is 192khz * sample time ( 60s ) = 11520000
short buff[1] = {0};

int main(){

    int i;

    FILE *wavFile;
    // Defines the log file.
    FILE *fileLog;

    // Create and Open the Log file.
    fileLog = fopen("A1-60sega.csv","ab");

    //Try if file is not empty return true.
    if ((wavFile = fopen("A1-60seg.wav", "rb")) == NULL){
        printf("Fail!");
        exit(1);
    }

    // Start the reading in 44º byte ( end of wave head file).
    //fseek(wavFile, 44, 0);

    // while remains data.
   while(!feof(wavFile)){
        //in each loop reads 1 byte
        fread(buff,sizeof(short),1,wavFile);
        fprintf(fileLog,"%i\n",buff[0]);
        //printf("%i\n",byteRead);
        };

    //close log file
    fclose(fileLog);
    fclose(wavFile);

    return 0;
}
