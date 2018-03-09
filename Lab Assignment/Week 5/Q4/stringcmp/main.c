#include <stdio.h>
#define INIT_VALUE 999
int stringcmp(char *s1, char *s2);
int main(){
   char source[80], target[80];
   int result = INIT_VALUE;

   printf("Enter a source string: \n");
   gets(source);
   printf("Enter a target string: \n");
   gets(target);
   result = stringcmp(source, target);
   if (result == 1)
      printf("stringcmp(): greater than");
   else if (result == 0)
      printf("stringcmp(): equal");
   else if (result == -1)
      printf("stringcmp(): less than");
   else
      printf("stringcmp(): error");
   return 0;
}

int stringcmp(char *s1, char *s2){
    int i, s1_len, s2_len, short_len;

    for (s1_len = 0; *(s1 + s1_len) != '\0'; s1_len++);
    for (s2_len = 0; *(s2 + s2_len) != '\0'; s2_len++);
    short_len = s1_len >= s2_len ? s2_len : s1_len;

    for (i = 0; i < short_len; i++){
        if (s1[i] == s2[i]) {continue;}
        else if (s1[i] > s2[i]) {return 1;}
        else {return -1;}
    }
    if (s1_len == s2_len) {return 0;}
    else if (s1_len > s2_len) {return 1;}
    else {return -1;}
}
