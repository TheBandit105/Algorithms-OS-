#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
    int n, i, *ptr, sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    ptr = (int*) malloc(n * sizeof(int));
    if(ptr == NULL)
    {   printf("Error! memory not allocated.");
        exit(0);
    }

    printf("Enter elements: ");
    for(i = 0; i < n; ++i) *(ptr + i) = -1;
    for(i = 0; i < n; ++i) sum += *(ptr + i);
    printf("Sum = %d \n", sum);
    sleep(10);
    free(ptr);
    return 0;
}
