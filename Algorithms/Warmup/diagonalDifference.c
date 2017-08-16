//@author: Varun Patel
//Diagonal Difference
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n;
    scanf("%d",&n);
    int a[n][n];
    for(int a_i = 0; a_i < n; a_i++){
        for(int a_j = 0; a_j < n; a_j++){
            
            scanf("%d",&a[a_i][a_j]);
        }
    }
    
    int middleIndex = 0;
    int rightSum = 0;
    int leftSum = 0;
    while(middleIndex < n) {
        rightSum += a[middleIndex][middleIndex];
        leftSum += a[n-middleIndex-1][middleIndex];
        middleIndex++;
    }
    printf("%d",abs(rightSum-leftSum));
    return 0;
}
