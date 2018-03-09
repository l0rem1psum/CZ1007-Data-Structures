#include <stdio.h>
void swapMinMax1D(int ar[], int size);
int main(){
    int ar[50],i,size;

    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    for (i=0; i<size; i++){
        scanf("%d",ar+i);
    }
    swapMinMax1D(ar, size);
    printf("swapMinMax1D(): ");
    for (i=0; i<size; i++){
        printf("%d ",*(ar+i));
    }
    return 0;
}
void swapMinMax1D(int ar[], int size){
    int max_index = 0, min_index = 0, tmp;
    int max = *ar;
    int min = *ar;

    for (int i = 0; i < size; i++){
        if (*(ar + i) >= max){
            max = *(ar + i);
            max_index = i;
        }
        if (*(ar + i) <= min){
            min = *(ar + i);
            min_index = i;
        }
    }
    tmp = *(ar + max_index);
    *(ar + max_index) = *(ar + min_index);
    *(ar + min_index) = tmp;
}
