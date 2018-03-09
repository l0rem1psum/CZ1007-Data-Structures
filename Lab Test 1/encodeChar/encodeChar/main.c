#include <stdio.h>
typedef struct {
    char source;
    char code;
} Rule;
void encodeChar(Rule table[5], char *s, char *t);
int main()
{
    char s[80],t[80];
    Rule table[5] = {'a','d', 'b','z', 'z','a', 'd','b', '\0','\0' };

    printf("Source string: \n");
    gets(s);
    encodeChar(table,s,t);
    printf("Encoded string: %s\n", t);
    return 0;
}

void encodeChar(Rule table[5], char *s, char *t)
{
    int i = 0, j;
    while (*(s + i)){
        for (j = 0; j < 5; j++){
            if (*(s + i) == (table + j) -> source){
                *(t + i) = (table + j) -> code;
                break;
            }
        }
        if (j == 5){*(t + i) = *(s + i);}
        i++;
    }
    t[i] = '\0';
}
