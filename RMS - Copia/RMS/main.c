#include<stdio.h>
#include<stdlib.h>




int main(){

    FILE *file_log;
    int i = 0, byteRead;

    // create a window with 30ms width.
    char buffer_window[200];

    file_log = fopen("SenLog.csv","ab");



    // Scrolls the array.
    do{
        fread(buffer_window,sizeof(buffer_window),48,file_log);
        printf("%i Elemento Lido %d \n", i+1, buffer_window[i]);
        //printf("Total lido: %d \n", byteRead);
        i++;

    }while(i < 48);

    fclose(file_log);





return 0;
}
