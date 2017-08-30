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
#define MAX(a,b) (((a)>(b))?(a):(b))
int getMaximumCost(int *masterArray, int arrayLength) {
    int high = 0, low = 0;
    for (int i = 1; i < arrayLength; i++) {
        int highToLow = abs(masterArray[i-1] - 1);
        int lowToHigh = abs(masterArray[i] - 1);
        int highToHigh = abs(masterArray[i] - masterArray[i-1]);
        int lowCopy = low;
        int highCopy = high;
        low = MAX(lowCopy,highCopy+highToLow);
        high = MAX(highCopy+highToHigh,lowCopy+lowToHigh);
    }
    return MAX(high,low);
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
        printf("%d\n", getMaximumCost(masterArray, arrayLength));
        free(masterArray);
    }
    return 0;
}
