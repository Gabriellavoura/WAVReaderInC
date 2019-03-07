#include<stdio.h>
#include<stdlib.h>



int main(){

    FILE *file_log;
    int i;

    // create a window with 30ms width.
    short buffer_window[48] = {0};

    file_log = fopen("logFile.csv","ab");

    // Scrolls the array.
    for (i = 0; i < 48; i++){

        fread( buffer_window[i],sizeof(short),48,file_log);
        printf("%d",buffer_window[i]);

    }





return 0;
}
