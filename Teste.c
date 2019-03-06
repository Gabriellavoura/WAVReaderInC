#include <stdio.h>
int main(){
  float vteste;
  printf(" --- TIPO ---|--- BYTES ---\n");
  printf(" char .......: %d bytes\n", sizeof(char));
  printf(" short.......: %d bytes\n", sizeof(short));
  printf(" int.........: %d bytes\n", sizeof(int));
  printf(" long........: %d bytes\n", sizeof(long));
  printf(" float ......: %d bytes\n", sizeof(float));
  printf(" double......: %d bytes\n", sizeof(double));
  printf(" long double.: %d bytes\n\n", sizeof(long double));

  printf("\nO tamanho de vteste e...: %d \n\n",sizeof vteste);

  getch();
  return 0;
}
