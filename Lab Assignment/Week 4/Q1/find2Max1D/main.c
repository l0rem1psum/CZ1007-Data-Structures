#include<stdio.h>
void find2Max1D(int ar[], int size, int *max1, int *max2);

int main(){
    int max1, max2;
    int ar[10], size, i;

    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    for (i = 0; i < size; i++){
        scanf("%d", &ar[i]);
    }
    find2Max1D(ar, size, &max1, &max2);
    printf("Max1: %d\nMax2: %d\n", max1, max2);
    return 0;
}

void find2Max1D(int ar[], int size, int *max1, int *max2){
    *max1 = *ar, *max2 = *ar;
    for (int i = 0; i < size; i++){
        if (*(ar + i) > *max1){
            *max2 = *max1;
            *max1 = *(ar + i);
        } else if (*max2 < *(ar + i) && *(ar + i) < *max1){
            *max2 = *(ar + i);
        } else if (*(ar + i) < *max2 && *max1 == *max2){
            *max2 = *(ar + i);
        }
    }
}
