//@author: Varun Patel
//Maximum Perimeter Triangle
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int comparator (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int main() {
    int arrayLength;
    scanf("%d", &arrayLength);
    int *arr = malloc(sizeof(int)*arrayLength);
    
    for (int i = 0; i < arrayLength; i++){
        scanf("%d", &arr[i]);
    }
    qsort(arr, arrayLength, sizeof(int), comparator);
    
    int j = arrayLength - 3;
    while ( j >= 0){
        if (arr[j] + arr[j+1] <= arr[j+2] ) {
            j--;
        } else {
            break;
        }
    }
    
    if (j < 0) {
        printf("-1");
    } else {
        printf ("%d %d %d", arr[j], arr[j+1], arr[j+2]);
    }
    free(arr);
    return 0;
}

