#include <stdio.h>
int platform1D(int ar[], int size);
int main()
{
    int i,b[50],size;
    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    for (i=0; i<size; i++)
        scanf("%d",&b[i]);
    printf("platform1D(): %d\n", platform1D(b,size));
    return 0;
}
int platform1D(int ar[], int size){
    int i, platform_len = 1, max_len = 1;
    for (i = 1; i < size; i++){
        if (*(ar + i) == *(ar + i - 1)){
            platform_len++;
        } else {
            platform_len = 1;
        }
        if (max_len < platform_len){
            max_len = platform_len;
        }
    }
    return max_len;
}
