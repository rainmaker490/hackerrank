//@author: Varun Patel
//Equal
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <limits.h>

/* Algorithm / Example :
2 (7) 7 7 7 7
7 7 (12) 12 12 12
12 12 12 (19) 19 19
17 17 17 (19) 24 24
19 19 19 (19) 26 26

 3 2 7 7 7
 3 3 7 7 7
 
 */

/* Input :
1
4
2 2 3 7 
 */

//Wrong:
int getMinimumIterations(int *distributedCandies, int index, int arrayLength,int *rightOffset) {
    //printf("%d",index);
    printf("\n");
    if (index == 0) {
        return 0;
    }
    
    if (index >= arrayLength){
        return 0;
    }
    int iterations = 0;
    int right = *rightOffset;
    if (right + distributedCandies[index] > distributedCandies[index-1]) {
        while (distributedCandies[index-1] != right + distributedCandies[index]) {
            //printf("%d, %d \n",distributedCandies[index-1],right + distributedCandies[index]);
            int offset = 1;
            if(right + distributedCandies[index] - distributedCandies[index-1] >= 5) {
                offset = 5;
            } else if (right + distributedCandies[index] - distributedCandies[index-1] >= 2) {
                offset = 2;
            }
            distributedCandies[index-1] = distributedCandies[index-1] + offset;
            (*rightOffset) =  (*rightOffset) + offset;
            iterations++;
        }
    } else if (distributedCandies[index] <  distributedCandies[index-1]) {
        while (distributedCandies[index-1] != distributedCandies[index]) {
            //printf("%d, %d \n",distributedCandies[index-1],distributedCandies[index]);
            int offset = 1;
            if(distributedCandies[index - 1] - distributedCandies[index] >= 5){
                offset = 5;
            } else if (distributedCandies[index - 1] - distributedCandies[index] >= 2) {
                offset = 2;
            }
            distributedCandies[index] = distributedCandies[index] + offset;
            (*rightOffset) =  (*rightOffset) + offset;
            iterations++;
        }
    }
    
    for (int i = 0; i <=index; i++){
        printf("%d, ",distributedCandies[i]);
    }
    for (int i = index + 1; i < arrayLength; i++){
        printf("%d, ",(*rightOffset)+distributedCandies[i]);
    }
    
    iterations+=getMinimumIterations(distributedCandies, index + 1, arrayLength,rightOffset);
    
    return iterations;
}

//Correct:
int getMinIterations(int *distributedCandies, int array_size, int minIndex) {
    int sum = INT_MAX;
    for(int i = 0; i < 3; i++) {
        int current = 0;
        for(int j = 0; j < array_size; j++) {
            int delta = distributedCandies[j] - distributedCandies[minIndex] + i;
            current += delta / 5 + delta % 5 / 2 + delta % 5 % 2 / 1;
        }
        sum = current < sum ? current : sum;
    }
    
    return sum;
}

int main() {
    int queries;
    scanf("%d",&queries);
    for (int i = 0; i < queries; i++) {
        int arrayLength;
        scanf("%d", &arrayLength);
        int *distributedCandies = malloc(arrayLength*sizeof(int));
        
        int minIndex = 0;
        for(int j = 0; j < arrayLength; j++){
            scanf("%d",&distributedCandies[j]);
            if (distributedCandies[minIndex] > distributedCandies[j]) {
                minIndex = j;
            }
        }
        int rightOffset = 0;
        //int minimumIterations = getMinimumIterations(distributedCandies,1,arrayLength, &rightOffset);
        int minimumIterations = getMinIterations(distributedCandies,arrayLength,minIndex);
        printf("%d\n",minimumIterations);
        free(distributedCandies);
    }
    return 0;
}
