#include <stdio.h>
int longWordLength(char *s);
int main() {
   char str[80];

   printf("Enter a string: \n");
   gets(str);
   printf("longWordLength(): %d\n", longWordLength(str));
   return 0;
}
int longWordLength(char *s){
    int max = 0, len = 0;
    while(*s){
        if (*s != ' ' && ((*s >= 'a' && *s <= 'z')|(*s >= 'A' && *s <= 'Z'))){
            len++;
            s++;
            continue;
        } else {
            if (len > max){
                max = len;
            }
            len = 0;
            s++;
        }
   }
   return max;
}
