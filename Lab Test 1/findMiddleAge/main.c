#include <stdio.h>
typedef struct {
    char name[20];
    int age;
} Person;
void readData(Person *p);
Person findMiddleAge(Person *p);
int main()
{
    Person man[3], middle;

    readData(man);
    middle = findMiddleAge(man);
    printf("findMiddleAge(): %s %d\n", middle.name, middle.age);
    return 0;
}

void readData(Person *p)
{
    int i;
    for (i = 0; i < 3; i++){
        printf("Enter person %d:\n", i + 1);
        scanf("%s %d", p[i].name, &((p + i) -> age));
    }
}

Person findMiddleAge(Person *p)
{
    Person mid;
    if (((p + 0) -> age) <= ((p + 1) -> age)){
        if (((p + 0) -> age) >= ((p + 2) -> age)){
            mid = p[0];
        } else {
            if (((p + 1) -> age) >= ((p + 2) -> age)){
                mid = p[2];
            } else {
                mid = p[1];
            }
        }
    } else {
        if (((p + 0) -> age) <= ((p + 2) -> age)){
            mid = p[0];
        } else {
            if (((p + 1) -> age) >= ((p + 2) -> age)){
                mid = p[1];
            } else {
                mid = p[2];
            }
        }
    }
    return mid;
}
