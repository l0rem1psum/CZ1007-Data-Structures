#include <stdio.h>
void processString(char *str, int *totVowels, int *totDigits);
int main(){
    char str[50];
    int totVowels = 0, totDigits = 0;
    printf("Enter the string: \n");
    gets(str);
    processString(str, &totVowels, &totDigits);
    printf("Total vowels = %d\n", totVowels);
    printf("Total digits = %d\n", totDigits);
    return 0;
}

void processString(char *str, int *totVowels, int *totDigits){
    int i = 0;
    while(*(str + i)){
        if ((*(str + i) == 'a') | (*(str + i) == 'e') |(*(str + i) == 'i') |(*(str + i) == 'o') |(*(str + i) == 'u') | (*(str + i) == 'A') | (*(str + i) == 'E') |(*(str + i) == 'I') |(*(str + i) == 'O') |(*(str + i) == 'U')){
            (*totVowels)++;
        } else if (*(str + i) >= 48 && *(str + i) <= 57){
            (*totDigits)++;
        }
        i++;
    }

}
