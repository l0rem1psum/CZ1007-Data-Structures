#include <stdio.h>
#define INIT_VALUE -1
int palindrome(char *str);
int main()
{
    char str[80];
    int result = INIT_VALUE;

    printf("Enter a string: \n");
    gets(str);
    result = palindrome(str);
    if (result == 1)
        printf("palindrome(): A palindrome\n");
    else if (result == 0)
        printf("palindrome(): Not a palindrome\n");
    else
        printf("An error\n");
    return 0;
}
int palindrome(char *str)
{
    int i, len = 0;
    while(*(str + len)){len++;}
    for (i = 0; i < len / 2; i++){
        if (*(str + i) != *(str + len - 1 - i)){return 0;}
    }
    return 1;
}
