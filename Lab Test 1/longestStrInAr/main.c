#include <stdio.h>
#include <string.h>
#define N 20
char *longestStrInAr(char str[N][40], int size, int *length);
int main(){
    int i, size, length;
    char str[N][40], *p;
    char dummychar;

    printf("Enter array size: \n");
    scanf("%d", &size);
    scanf("%c", &dummychar);
    for (i=0; i<size; i++) {
        printf("Enter string %d: \n", i+1);
        gets(str[i]);
    }
    p = longestStrInAr(str, size, &length);
    printf("longest: %s \nlength: %d\n", p, length);
    return 0;
}

char *longestStrInAr(char str[N][40], int size, int *length){
    int i;
    static char longestStr[40];
    *length = 0;
    for (i = 0; i < size; i++){
        if (strlen(str[i]) > *length){
            *length = strlen(str[i]);
            strcpy(longestStr, str[i]);
        }
    }
    return longestStr;
    /*
    Alternative Method:
    int i;
    char *longestStr;
    *length = 0;
    for (i = 0; i < size; i++){
        if (strlen(str[i]) > *length){
            *length = strlen(str[i]);
            longestStr = str[i]
        }
    }
    return longestStr;
    */
}
