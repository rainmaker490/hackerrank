//@author: Varun Patel
//Beautiful Pairs
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int comparator (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int main() {
    int arrayLength;
    scanf("%d",&arrayLength);
    int *arr_a = malloc(arrayLength*sizeof(int));
    int *arr_b = malloc(arrayLength*sizeof(int));
    
    for (int i = 0; i < arrayLength; i++){
        scanf("%d",&arr_a[i]);
    }
    
    for (int i = 0; i < arrayLength; i++){
        scanf("%d",&arr_b[i]);
    }
    qsort(arr_a, arrayLength, sizeof(int), comparator);
    qsort(arr_b, arrayLength, sizeof(int), comparator);
    int beautiful = 0;
    int i = 0;
    int j = 0;
    while (i < arrayLength && j < arrayLength) {
        if (arr_a[i] == arr_b[j]) {
            i++;
            j++;
            beautiful++;
        } else if (arr_a[i] < arr_b[j]){
            i++;
        } else {
            j++;
        }
    }
    
    if (beautiful == arrayLength){
        beautiful--;
    } else {
        beautiful++;
    }
    
    printf("%d",beautiful);
    free(arr_a);
    free(arr_b);
    return 0;
}
