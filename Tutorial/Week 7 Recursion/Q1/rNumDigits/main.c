#include <stdio.h>
int rNumDigits1(int num);
void rNumDigits2(int num, int *result);
int main()
{
    int number, result=0;

    printf("Enter the number: \n");
    scanf("%d", &number);
    printf("rNumDigits1(): %d\n", rNumDigits1(number));
    rNumDigits2(number, &result);
    printf("rNumDigits2(): %d\n", result);
    return 0;
}

int rNumDigits1(int num)
{
    if (num < 10){return 1;}
    else {return 1 + rNumDigits1(num / 10);}
}

void rNumDigits2(int num, int *result)
{
    if (num < 10){(*result)++;}
    else {
        rNumDigits2(num / 10, result);
        (*result)++;
    }
}
