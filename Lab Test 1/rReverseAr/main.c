#include <stdio.h>
void rReverseAr(int ar[], int size);
int main()
{
    int array[80];
    int size, i;
    printf("Enter size: \n");
    scanf("%d", &size);
    printf("Enter %d numbers: \n", size);
    for (i = 0; i < size; i++)
        scanf("%d", &array[i]);
    printf("rReverseAr(): ");
    rReverseAr(array, size);
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
    return 0;
}

void rReverseAr(int ar[], int size)
{
    if (size == 1){
        return;
    } else {
        rReverseAr(ar + 1, size - 1);
        int i, temp;
        temp = *ar;
        for (i = 0; i < size - 1; i++){
            *(ar + i) = *(ar + i + 1);
        }
        *(ar + size - 1) = temp;
    }
}
