#include <stdio.h>
void maxCharToFront(char *str);
int main()
{
   char str[80];
   printf("Enter a string: \n");
   gets(str);
   printf("maxCharToFront(): ");
   maxCharToFront(str);
   puts(str);
   return 0;
}
void maxCharToFront(char *str){
    char max = *str;
    int pos = 0, i = 0;
    while(*(str + i)){
        if (*(str + i) > max) {
            max = *(str + i);
            pos = i;
        }
        i++;
    }

    for (i = pos; i > 0; i--){
        str[i] = str[i - 1];
    }
    *str = max;
}
