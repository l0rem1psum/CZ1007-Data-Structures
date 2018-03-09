#include <stdio.h>
int countSubstring(char str[], char substr[]);
int isSubstring(char str[], char substr[]);
int main()
{
    char str[80],substr[80];

    printf("Enter the string: \n");
    gets(str);
    printf("Enter the substring: \n");
    gets(substr);
    printf("countSubstring(): %d\n", countSubstring(str, substr));
    return 0;
}

int countSubstring(char str[], char substr[])
{
    int i = 0, count = 0, substr_len = 0;
    while(*(substr + substr_len)){substr_len++;}

    while(*(str + i)){
        if (isSubstring(str + i, substr)){
            count ++; i += substr_len;
        } else {i++;}
    }
    return count;
}

int isSubstring(char str[], char substr[])
{
    int i = 0, j, k, substr_len = 0;
    while(*(substr + substr_len)){substr_len++;}

    while(*(str + i)){
        j = 0; k = i;
        while(*(substr + j)){
            if (*(str + k) == *(substr + j)){
                k++; j++;
                continue;
            } else {
                break;
            }
        }
        if (j == substr_len){
            return 1;
        }
        i++;
    }
    return 0;
}
