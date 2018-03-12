#include <stdio.h>
void rFindMaxAr(int *ar, int size, int i, int *index);
int main()
{
    int ar[50],i,maxIndex=0,size;
    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d numbers: \n", size);
    for (i=0; i < size; i++)
        scanf("%d", &ar[i]);
    rFindMaxAr(ar,size,0,&maxIndex);
    printf("Max number: %d\n", ar[maxIndex]);
    printf("Index position: %d\n", maxIndex);
    return 0;
}

void rFindMaxAr(int *ar, int size, int i, int *index)
/*Not sure what the integer i hear means, since it is never used.*/
{
    if (size == 1){
        *index = 0;
    } else {
        rFindMaxAr(ar + 1, size - 1, i, index);
        if (*ar > *(ar + *index + 1)){
            *index = 0;
        } else {
            (*index)++;
        }
    }
}
