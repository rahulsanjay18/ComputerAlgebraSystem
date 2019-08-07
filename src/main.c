#include <stdio.h>

int returnVal() {
  getchar();
  return 0;
}

int main()
{
   // printf() displays the string inside quotation
   printf("Hello, Main!\n");
   return returnVal();
}