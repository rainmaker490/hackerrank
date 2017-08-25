//@author: Varun Patel
//The Longest Increasing Subsequence
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
 5
 2
 7
 4
 3
 8
 ------->
 3
 */

//TODO:
int getLongestIncreasingSubsequence() {
    return 0;
}

int main() {
    int queries;
    scanf("%d",&queries);
    
    int *lisArray = malloc(queries*sizeof(int));
    for(int i = 0; i < queries; i++) {
        scanf("%d",&lisArray[i]);
    }
    
    int lis = getLongestIncreasingSubsequence();
    printf("%d",lis);
    return 0;
}
