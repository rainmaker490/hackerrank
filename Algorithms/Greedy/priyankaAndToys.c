//@author: Varun Patel
//Priyanka And Toys
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int comparator (const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int arrayLength;
    scanf("%d", &arrayLength);
    int *arr = malloc(sizeof(int)*arrayLength);
    for (int i = 0; i < arrayLength; i++){
        scanf("%d",&arr[i]);
    }
    qsort(arr,arrayLength,sizeof(int),comparator);
    int cost = 0;
    for (int i = 0; i < arrayLength; i++){
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < arrayLength;){
        int currentCost = arr[i]+4;
        int j = i+1;
        while (currentCost >= arr[j]){
            j++;
        }
        i=j;
        cost++;
    }
    printf("%d",cost);
    free(arr);
    return 0;
}

