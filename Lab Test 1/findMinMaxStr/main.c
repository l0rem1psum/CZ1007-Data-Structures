#include <stdio.h>
#include <string.h>
#define SIZE 10
void findMinMaxStr(char word[][40], char *first, char *last, int size);
int compareWord(char *word1, char *word2);
int main()
{
    char word[SIZE][40];
    char first[40], last[40];
    int i, size;

    printf("Enter size: \n");
    scanf("%d", &size);
    printf("Enter %d words: \n", size);
    for (i=0; i<size; i++)
        scanf("%s", word[i]);
    findMinMaxStr(word, first, last, size);
    printf("First word = %s, Last word = %s\n", first, last);
    return 0;
}

void findMinMaxStr(char word[][40], char *first, char *last, int size){
    int i;
    strcpy(first, *word);
    strcpy(last, *word);
    for (i = 0; i < size; i++){
        if(compareWord(*(word + i), last)){strcpy(last, *(word + i));}
        if(!compareWord(*(word + i), first)){strcpy(first, *(word + i));}
    }
}

int compareWord(char *word1, char *word2){
    int i = 0;
    while(*(word1 + i) | *(word2 + i)){
        if (*(word1 + i) > *(word2 + i)){return 1;}
        else if (*(word1 + i) < *(word2 + i)){return 0;}
        i++;
    }
    return 1;
}
