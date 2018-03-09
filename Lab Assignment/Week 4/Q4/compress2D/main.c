#include <stdio.h>
#define SIZE 100
void compress2D(int data[SIZE][SIZE], int rowSize, int colSize);
int main() {
   int data[SIZE][SIZE];
   int i,j;
   int rowSize, colSize;

   printf("Enter the array size (rowSize, colSize): \n");
   scanf("%d %d", &rowSize, &colSize);
   printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
   for (i=0; i<rowSize; i++)
       for (j=0; j<colSize; j++)
         scanf("%d", &data[i][j]);
   printf("compress2D(): \n");
   compress2D(data, rowSize, colSize);
   return 0;
}
void compress2D(int data[SIZE][SIZE], int rowSize, int colSize){
    for (int i = 0; i < rowSize; i++){
        int current_number = *(*(data + i) + 0), counter = 0;
        for (int j = 0; j < colSize; j++){
            if (*(*(data + i) + j) == current_number){
                counter++;
            } else {
                printf("%d %d ", current_number, counter);
                counter = 1;
                current_number = *(*(data + i) + j);
            }
        }
        printf("%d %d\n", current_number, counter);
   }
}
