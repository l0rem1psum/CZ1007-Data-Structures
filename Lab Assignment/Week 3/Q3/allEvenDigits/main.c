#include <stdio.h>
#define INIT_VALUE -1
int allEvenDigits1(int sum);
void allEvenDigits2(int num, int *result);
int removeLastDigit(int num);

int main(){
    int number, result = INIT_VALUE;

    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("allEvenDigits1(): ");
    result = allEvenDigits1(number);
    if (result == 1){
        printf("All Even\n");
    } else if (result == 0) {
        printf("Not All Even\n");
    } else {
        printf("Error\n");
    }
    allEvenDigits2(number, &result);
    printf("allEvenDigits2(): ");
    if (result == 1){
        printf("All Even\n");
    } else if (result == 0) {
        printf("Not All Even\n");
    } else {
        printf("Error\n");
    }
    return 0;
}

int allEvenDigits1(int num){
    int tmp_num = num;
    while(tmp_num != 0){
        if (tmp_num % 2 == 0){
            tmp_num = removeLastDigit(tmp_num);
        } else {
            return 0;
        }
    }
    return 1;
}

void allEvenDigits2(int num, int *result){
    while(num != 0){
        if (num % 2 == 0){
            num = removeLastDigit(num);
        } else {
            *result = 0;
            return;
        }
    }
    *result = 1;
}


int removeLastDigit(int num){
    return (num - num % 10) / 10;
}
