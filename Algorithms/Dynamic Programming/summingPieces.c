//@author: Varun Patel
//Summing Pieces
//A Non-Memoized C Solution:
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int getSummedPieces(int *summingPiecesArray,int startIndex, int endIndex,int *iterations) {
    if (startIndex > endIndex) {
        return 0;
    }
    
    int groups = 1;
    int currentSum = 0;
    int iter = 1;
    while (groups <= currentArraySize - startIndex) {
        int groupedSum = 0;
        for (int i = startIndex; i < startIndex+groups; i++;) {
            groupedSum += summingPiecesArray[groupedSum];
        }
        
        
        int subSum = getSummedPieces(summingPiecesArray,startIndex+groups,endIndex,&iter);
        currentSum += (iter*subSum);
        currentSum += groupedSum;
        
        iter++;
        groups++;
    }

}

int main() {
    int arrayLength;
    scanf("%d",&arrayLength);
    int summingPiecesArray = calloc(arrayLength,sizeof(int));
    for (int i = 0; i < arrayLength; i++) {
        scanf("%d",&summingPiecesArray[i]);
    }
    printf("%d",getSummedPieces(summingPiecesArray,0,arrayLength-1,0));
    return 0;
}

1 2 3 4 5
1 2 3 45
1 2 34 5
1 2 345
1 23 4 5
1 23 45
1 234 5
1 2345
12 3 4 5
12 3 45
12 34 5
12 345
123 4 5
123 45
1234 5
12345
