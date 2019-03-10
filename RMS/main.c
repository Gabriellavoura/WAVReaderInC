#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//Defines 30ms window size:
#define WINDOW_LENGHT 480

int main(){

    FILE * fp;

    int window[WINDOW_LENGHT];
    char str[126];
    int i=0;
    long long int a = 0, b = 0 , c =0;
    long long int RMS = 0;

    // Open the file and verify is NULL.
    if((fp = fopen("SenLog.csv","r")) == NULL){

        printf("Error! Can't open the file.\n");
        exit(1);
    }

    // Load the data in window.
    while(i < WINDOW_LENGHT){
        if(fgets(str,1240,fp)){
            //Transform string in integer and store in window array.
            window[i]= atoi(str);
            //printf("%d \n",windowSize[i]);
        }
        i++;
    }

    // Begin RMS Algorithm
    // First calculate the sum and square.
    for(i = 0; i < (WINDOW_LENGHT - 1); i++){

        a = window[i];
        //printf("A: %lld\n",a);

        b = window[i+1];
       // printf("B: %lld\n",b);

        c += ((a*a) + (b*b));
        //Printf("C: %lld\n",c);
    }

    // Calculate the root.
    RMS = sqrt(c / WINDOW_LENGHT);

    printf("RMS: %lld",RMS);

    fclose(fp);

    return(0);
}
