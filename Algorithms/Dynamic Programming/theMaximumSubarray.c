//@author: Varun Patel
//The Maximum Subarray
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/*
2
4
1 2 3 4
6
2 -1 2 3 4 -5
-------------------INPUT
10 10
10 11
-------------------OUTPUT
 */

int kadaneAlgorithm(int *array) {
    
    return 0;
}

int main() {
    int queries;
    scanf("%d",&queries);
    for (int i = 0; i < queries; i++) {
        int arrayLength;
        scanf("%d",&arrayLength);
        int *array = malloc(arrayLength*(sizeof(int)));
        
        int maximumNonContiguousSum = 0;
        int maxNumber;
        for (int j = 0; j < arrayLength; j++) {
            scanf("%d",&array[j]);
            if (j == 0) {
                maxNumber = array[0];
            } else if(maxNumber < array[j]) {
                maxNumber = array[j];
            }
            
            if(array[j] > 0) {
                maximumNonContiguousSum += array[j];
            }
        }
        
        if(maxNumber < 0) {
            maximumNonContiguousSum = maxNumber;
        }
        
        int maximumContiguousSum = kadaneAlgorithm(array);
        
        printf("%d %d\n",maximumContiguousSum, maximumNonContiguousSum);
    }
    return 0;
}

