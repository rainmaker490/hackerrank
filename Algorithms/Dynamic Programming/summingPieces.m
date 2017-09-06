//@author: Varun Patel
//Summing Pieces
//Objective C Solution
#import <objc/objc.h>
#import <objc/Object.h>
#import <Foundation/Foundation.h>

/* Algorithm && Flow :
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

1 3 6
1 36
13 6
136
 */

int getSummedPieces(int *summingPiecesArray,int startIndex, int endIndex) {
    if (startIndex > endIndex) {
        //printf("Iterator  %d\n",startIndex-endIndex);
        return 0;
    }
    
    int groups = 1;
    int currentSum = 0;
    //printf("StartIndex:%d,EndIndex:%d\n",startIndex,endIndex);
    int loopCount = 1;
    while (groups - 1 < endIndex - startIndex + 1) {
        //printf("Groups:%d\n",groups);
        int groupedSum = 0;
        for (int i = startIndex; i <= startIndex+groups-1; i++){
            groupedSum+=summingPiecesArray[i];
        }
        /*
        for (int i = startIndex; i <= startIndex+groups-1; i++){
            printf("%d, ",summingPiecesArray[i]);
        }
        printf("\n");
         */
        
        int subSum = getSummedPieces(summingPiecesArray,startIndex+groups,endIndex);
        //printf("GroupedSum%d\n",groupedSum);
        //printf("GroupedTotal%d\n",groupedSum*groups);
        currentSum += subSum;
        int loopCount = endIndex - (startIndex + groups) ;
        //printf("LoopCount   %d\n",loopCount);
        if (loopCount < 0) {
            loopCount++;
            //printf("LoopCount   %d\n",loopCount);
            //printf("Loop Count Less Than 0\n");
        }
        //printf("GroupedSum: %d ,,,, LoopCount   %d \n",groupedSum,loopCount);
        currentSum += (groupedSum * pow(2,loopCount) * groups);
        //printf("CURRENTSUM   %d\n",currentSum);
        //printf("Iterator  %d\n",loopCount);
        //printf("GroupedSum%d\n",groupedSum);
        groups++;
    }
    return currentSum;
}

int main(int argc, const char *argv[]) {
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    int arrayLength;
    scanf("%i",&arrayLength);
    int summingPiecesArray[arrayLength];
    for (int i = 0; i < arrayLength; i++) {
        scanf("%i",&summingPiecesArray[i]);
    }
    printf("%i\n",getSummedPieces(summingPiecesArray,0,arrayLength-1));
    [pool drain];
    return 0;
}
