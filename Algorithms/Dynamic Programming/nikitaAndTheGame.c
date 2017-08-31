//@author: Varun Patel
//Nikita and the Game
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/*
 3
 3
 3 3 3
 4
 2 2 2 2
 7
 4 1 0 1 1 0 1
 24
 2 0 0 2 2 0 0 0 0 2 0 2 0 2 0 2 0 0 0 2 0 0 2 0
 42
 0 2 0 2 0 0 0 0 2 0 0 2 2 0 2 2 2 2 0 0 0 2 0 0 2 2 2 2 2 2 0 0 0 0 2 0 2 0 2 0 2 2
 --------------------------------------------------------------------------------------->
 0
 2
 3
 0
 0
 */
#define MAX(a,b) (((a)>(b))?(a):(b))
int getMoves (int *nikitasArray, int leftIndex, int rightIndex, long long currentSum) {
    //DEBUG: printf("leftIndex: %d, rightIndex: %d \n",leftIndex,rightIndex);
    int moves = 0;
    if (leftIndex >= rightIndex || currentSum %2 == 1) {
        return 0;
    }
    
    long long localSum = 0;
    int i = leftIndex;
    for (; i <= rightIndex; i++) {
        localSum+= nikitasArray[i];
        if (localSum == currentSum / 2) {
            break;
        }
    }
    if (i < rightIndex) {
        moves++;
        int leftMoves = 0;
        leftMoves += getMoves(nikitasArray,leftIndex,i,currentSum/2);
        int rightMoves = 0;
        rightMoves += getMoves(nikitasArray,i+1,rightIndex,currentSum/2);
        moves += MAX(leftMoves,rightMoves);
    }
    return moves;
}


int main() {
    int queries;
    scanf("%d", &queries);
    for (int i = 0; i < queries; i++) {
        int arraySize;
        scanf("%d", &arraySize);
        int *nikitasArray = calloc(arraySize, sizeof(int));
        long long unsigned currentSum = 0;
        for (int j = 0; j < arraySize; j++) {
            scanf("%d",&nikitasArray[j]);
            currentSum += nikitasArray[j];
        }
        printf("%d\n",getMoves(nikitasArray,0,arraySize-1,currentSum));
        free(nikitasArray);
    }
    return 0;
}
