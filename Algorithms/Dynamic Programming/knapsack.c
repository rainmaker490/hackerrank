//@author: Varun Patel
//Knapsack
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
 2
 3 12
 1 6 9
 5 9
 3 4 4 4 8
 ------------>
 12
 9
 
 1
 3 13
 3 10 4
 ------------>
 13
 */

int knapsackDifference(int *knapSackArray, int knapSackArraySize, int minimumDifference) {
    if (minimumDifference == 0) {
        return 0;
    }
    //printf("%d\n",minimumDifference);
    
    int currentMinimumDifference = minimumDifference;
    for (int j = 0; j < knapSackArraySize; j++) {
        //printf("j:%d\n",j);
        //printf("minimumDifference:%d \n", minimumDifference);
        //printf("KnapsackValue:%d \n", knapSackArray[j]);
        if (currentMinimumDifference % knapSackArray[j] == 0) {
            minimumDifference = 0;
            break;
        } else if (minimumDifference - knapSackArray[j] > 0) {
            int preMinimumDifference = minimumDifference;
            int post = knapsackDifference(&knapSackArray[j],knapSackArraySize-j,minimumDifference-knapSackArray[j]);
            int pre = -1;
            for (int i = j + 1 ; i < knapSackArraySize; i++){
                if (preMinimumDifference - knapSackArray[i] > 0) {
                    pre = knapsackDifference(&knapSackArray[i],knapSackArraySize-i,preMinimumDifference-knapSackArray[i]);
                }
                if (pre == 0) {
                    break;
                }
            }
            minimumDifference = post;
            if (pre != -1) {
                minimumDifference = post < pre ? post : pre;
            }
            //printf("PRE:%d POST:%d MinDif:%d\n",preMinimumDifference,post,minimumDifference);
        }
    }
    return minimumDifference;
}

int main() {
    int queries;
    scanf("%d",&queries);
    for (int i = 0; i < queries; i++){
        int arraySize, totalCount;
        scanf("%d %d", &arraySize, &totalCount);
        int *knapSackArray = malloc(sizeof(int)*arraySize);
        for (int knapSackArray_i = 0; knapSackArray_i < arraySize; knapSackArray_i++){
            scanf("%d",&knapSackArray[knapSackArray_i]);
        }
        int maxCount = totalCount - knapsackDifference(knapSackArray,arraySize,totalCount);
        printf("%d\n",maxCount);
    }
    return 0;
}
