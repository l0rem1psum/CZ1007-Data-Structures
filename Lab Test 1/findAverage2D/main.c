#include <stdio.h>
void findAverage2D(float matrix[4][4]);

int main(){
    float ar[4][4];
    int i, j;

    printf("Enter data: \n");
    for (i = 0; i < 4; i++){
        for (j = 0; j < 4; j++){
            scanf("%f", &ar[i][j]);
        }
    }
    findAverage2D(ar);
    printf("findAverage2D(): \n");
    for (i = 0; i < 4; i++){
        for (j = 0; j < 4; j++){
            printf("%.2f ", ar[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void findAverage2D(float matrix[4][4]){
    int m;
    for (m = 0; m < 4; m++){
        *(*(matrix + m) + 3) = (*(*(matrix + m) + 0) + *(*(matrix + m) + 1) + *(*(matrix + m) + 2))/3.0;
    }
}
