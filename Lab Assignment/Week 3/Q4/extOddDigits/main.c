#include<stdio.h>
#define INIT_VALUE 0
int extOddDigits1(int num);
void extOddDigits2(int num, int *result);

int main(){
    int number, result = INIT_VALUE;

    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("extOddDigits1(): %d\n", extOddDigits1(number));
    extOddDigits2(number, &result);
    printf("extOddDigits2(): %d\n", result);
    return 0;
}

int extOddDigits1(int num){
    int extracted_num = 0, weight = 1, tmp_num = num;
    while(tmp_num != 0){
        if(tmp_num % 2 != 0){
            extracted_num += (tmp_num % 10) * weight;
            weight *= 10;
        }
        tmp_num /= 10;
    }
    return (extracted_num == 0)? -1: extracted_num;
}

void extOddDigits2(int num, int *result){
    int extracted_num = 0, weight = 1, tmp_num = num;
    while(tmp_num != 0){
        if(tmp_num % 2 != 0){
            extracted_num += (tmp_num % 10) * weight;
            weight *= 10;
        }
        tmp_num /= 10;
    }
    *result = (extracted_num == 0)? -1: extracted_num;
}
