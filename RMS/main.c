#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//Defines 30ms window size:
#define WINDOW_LENGTH 480

int main(){

    FILE * fp;

    int window[WINDOW_LENGTH];
    char str[100];
    int i=0;
    double a = 0, c =0;
    int RMS = 0;

    // Open the file and verify is NULL.
    if((fp = fopen("SenLog.csv","r")) == NULL){

        printf("Error! Can't open the file.\n");
        exit(1);
    }

    // Load the data in window.
    while(i < WINDOW_LENGTH){
        if(fgets(str,100,fp)){
            //Transform string in integer and store in window array.
            window[i]= atoi(str);
            //printf("%d \n",windowSize[i]);
        }
        i++;
    }

    // Begin RMS Algorithm
    // First calculate the sum and square.
    for(i = 0; i < WINDOW_LENGTH; i++){

        a = window[i];
        //printf("A: %lld\n",a);

        c += (a*a);
       // printf("C: %lld\n",c);
    }

    // Calculate the root.
    c = c / WINDOW_LENGTH;
    RMS = sqrt(c);

    printf("RMS: %d",RMS);

    fclose(fp);

    return(0);
}
