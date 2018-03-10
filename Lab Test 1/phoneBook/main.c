#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct {
    char name[20];
    char telno[20];
} PhoneBk;
int readin(PhoneBk *p);
void search(PhoneBk *p, int size, char *target);
int main()
{
    PhoneBk s[MAX];
    char t[20];
    int size;
    size = readin(s);
    printf("Enter search name: \n");
    gets(t);
    search(s,size,t);
    return 0;
}

int readin(PhoneBk *p)
{
     int count = 0;
     char temp[20];
     while(1){
        printf("Enter name:\n");
        gets(temp);
        if (!strcmp(temp, "#")){break;}
        strcpy((p + count) -> name, temp);
        printf("Enter tel:\n");
        gets((p + count) -> telno);
        count++;
     }
     return count;
}
void search(PhoneBk *p, int size, char *target)
{
    int i;
    for (i = 0; i < size; i++){
        if(!strcmp((p + i) -> name, target)){
            printf("Name = %s, Tel = %s", (p + i) -> name, (p + i) -> telno);
            return;
        }
    }
    if (i == size){printf("Name not found!");}
}
