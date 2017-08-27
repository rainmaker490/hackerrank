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

//Algorithm Reference : https://en.wikipedia.org/wiki/Longest_increasing_subsequence
//O(nlogn) solution (binary search through tail Array);
//O(n^2) if bruteforce search through tail Array;

int binarySearch(int *lisTailArray, int lisArraySize, int searchNumber) {
    int leftPivot = 0;
    int rightPivot = lisArraySize;
    while(rightPivot-leftPivot > 1) {
        int middlePivot = leftPivot + (rightPivot - leftPivot)/2;
        if (lisTailArray[middlePivot] >= searchNumber){
            rightPivot = middlePivot;
        } else {
            leftPivot = middlePivot;
        }
    }
    return rightPivot;
}

int main() {
    int queries;
    scanf("%d",&queries);
    
    int *lisTailArray = calloc(queries+1,sizeof(int));
    
    int currentIndex = 0;
    int input;
    for(int i = 0; i <= queries; i++) {
        scanf("%d",&input);
        if(lisTailArray[currentIndex] < input) {
            currentIndex++;
            lisTailArray[currentIndex] = input;
        } else if(lisTailArray[currentIndex] > input) {
            int index = binarySearch(lisTailArray, currentIndex, input);
            lisTailArray[index] = input;
        }
    }
    printf("%d",currentIndex);
    free(lisTailArray);
    return 0;
}
