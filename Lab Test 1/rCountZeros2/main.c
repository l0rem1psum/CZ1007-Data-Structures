#include <stdio.h>
void rCountZeros2(int num, int *result);
int main()
{
    int number, result = 0;
    printf("Enter the number: \n");
    scanf("%d", &number);
    rCountZeros2(number,&result);
    printf("rCountZeros2(): %d\n", result);
    return 0;
}

void rCountZeros2(int num, int *result)
{
    if (num < 10 && num >= 0){
        if (num == 0){(*result)++; return;}
        else {return;}
    } else {
        if (num % 10 == 0){(*result)++;}
        rCountZeros2(num / 10, result);
    }
}
