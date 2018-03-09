#include <stdio.h>
int rDigitValue1(int num, int k);
int main()
{
    int k, number;

    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("Enter k position: \n");
    scanf("%d", &k);
    printf("rDigitValue1(): %d\n", rDigitValue1(number, k));
    return 0;
}

int rDigitValue1(int num, int k)
{
    if (k == 1){
        return num % 10;
    } else {
        return rDigitValue1(num/10, k-1);
    }
}
