#include <stdio.h>
#include <string.h>
#include <ctype.h>
void cipher(char *s);
void decipher(char *s);
int main(){
    char str[80];

    printf("Enter the string: \n");
    gets(str);
    printf("To cipher: %s -> ", str);
    cipher(str);
    printf("%s\n", str);
    printf("To decipher: %s -> ", str);
    decipher(str);
    printf("%s\n", str);
    return 0;
}

void cipher(char *s){
    int i = 0;
    while (*(s + i)){
        if (isalpha(*(s + i)) && *(s + i) != '\x5A' && *(s + i) != '\x7A'){(*(s + i))++;}
        else if (*(s + i) == '\x5A'){*(s + i) = '\x41';}
        else if (*(s + i) == '\x7A'){*(s + i) = '\x61';}
        i++;
    }
}
void decipher(char *s){
    int i = 0;
    while (*(s + i)){
        if (isalpha(*(s + i)) && *(s + i) != '\x41' && *(s + i) != '\x61'){(*(s + i))--;}
        else if (*(s + i) == '\x41'){*(s + i) = '\x5A';}
        else if (*(s + i) == '\x61'){*(s + i) = '\x7A';}
        i++;
    }
}
