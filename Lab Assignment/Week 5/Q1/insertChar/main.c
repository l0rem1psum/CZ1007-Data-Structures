#include <stdio.h>
#include <string.h>
void insertChar(char *str1, char *str2, char ch);
int main() {
   char a[80],b[80];
   char ch;

   printf("Enter a string: \n");
   gets(a);
   printf("Enter a character to be inserted: \n");
   ch = getchar();
   insertChar(a,b,ch);
   printf("insertChar(): ");
   puts(b);
   return 0;
}

void insertChar(char *str1, char *str2, char ch){
  int i = 0, count = 0;
  while(*str1){
    str2[i + count] = *str1++;
    if(i % 3 == 2){
        count++;
        str2[i + count] = ch;
    }
    i++;
  }
  str2[i + count] = '\0';
}
