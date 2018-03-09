#include <stdio.h>
#define INIT_VALUE -1
int findSubstring(char *str, char *substr);
int main()
{
    char str[40], substr[40];
    int result = INIT_VALUE;
    printf("Enter the string: \n");
    gets(str);
    printf("Enter the substring: \n");
    gets(substr);
    result = findSubstring(str, substr);
    if (result == 1)
        printf("findSubstring(): Is a substring\n");
    else if ( result == 0)
        printf("findSubstring(): Not a substring\n");
    else
        printf("findSubstring(): An error\n");
    return 0;
}

int findSubstring(char *str, char *substr)
{
    int i = 0, j, k, substr_len = 0;
    while(*(substr + substr_len)){substr_len++;}

    while(*(str + i)){
        j = 0; k = i;
        while(*(substr + j)){
            if (*(substr + j) == *(str + k)){
                j++; k++;
                continue;
            } else {
                break;
            }
        }
        if (j == substr_len){return 1;}
        i++;
    }
    return 0;
}
