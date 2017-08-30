//@author: Varun Patel
//Sherlock and Cost
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/*
 1
 5
 10 1 10 1 10
 --------------->
 36
 */

int getMaximumCost(int *masterArray) {
    
    return 0;
}

int main() {
    int queries;
    scanf("%d", &queries);
    for (int i = 0; i < queries; i++) {
        int arrayLength;
        scanf("%d", &arrayLength);
        int *masterArray = calloc(arrayLength, sizeof(int));
        for (int j = 0; j < arrayLength; j++) {
            scanf("%d", &masterArray[j]);
        }
        printf("%d\n", getMaximumCost(masterArray));
        free(masterArray);
    }
    return 0;
}
