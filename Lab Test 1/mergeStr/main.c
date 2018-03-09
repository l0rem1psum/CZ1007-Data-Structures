#include <stdio.h>
#include <string.h>
void mergeStr(char *a, char *b, char *c);
int main()
{
    char a[80],b[80];
    char c[80];
    printf("Enter the first string: \n");
    gets(a);
    printf("Enter the second string: \n");
    gets(b);
    mergeStr(a,b,c);
    printf("mergeStr(): ");
    puts(c);
    return 0;
}

void mergeStr(char *a, char *b, char *c){
    int i, j = 0, k;
    strcpy(c, a);
    while(*(b + j)){
        k = 0;
        while(*(c + k)){
            if (*(c + k) > *(b + j)){
                for (i = strlen(c); i >= k; i--){
                    *(c + i + 1) = *(c + i);
                }
                *(c + k) = *(b + j);
                break;
            } else if ((*(c + k) < *(b + j)) && k == strlen(c) - 1){
                *(c + k + 2) = '\0';
                *(c + k + 1) = *(b + j);
            }
            k++;
        }
        j++;
    }
}
