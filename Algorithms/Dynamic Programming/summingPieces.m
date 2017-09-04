//@author: Varun Patel
//Summing Pieces
//Objective C Solution
#import <objc/objc.h>
#import <objc/Object.h>
#import <Foundation/Foundation.h>
int getSummedPieces(int *summingPiecesArray,int startIndex, int endIndex,NSMutableDictionary **iterationsDictionary) {
    if (startIndex > endIndex) {
        //printf("Iterator  %d\n",*iterations);
        return 0;
    }
    
    int groups = 1;
    int currentSum = 0;
    //printf("StartIndex:%d,EndIndex:%d\n",startIndex,endIndex);
    int subLoopCount = 1;
    while (groups <= endIndex - startIndex + 1) {
        //printf("Groups:%d\n",groups);
        int groupedSum = 0;
        for (int i = startIndex; i <= startIndex+groups; i++){
            groupedSum+=summingPiecesArray[i];
        }
        int subSum = getSummedPieces(summingPiecesArray,startIndex+groups,endIndex,iterationsDictionary);
        //printf("GroupedSum%d\n",groupedSum);
        //printf("GroupedTotal%d\n",groupedSum* *iterations);
        currentSum += subSum;
        int totalLoopCount = 0;
        currentSum += groupedSum * totalLoopCount;
        //printf("Iterator  %d\n",*iterations);
        //printf("GroupedSum%d\n",groupedSum);
        subLoopCount++;
        groups++;
    }
    return currentSum;
}

int main(int argc, const char *argv[]) {
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    int arrayLength;
    scanf("%d",&arrayLength);
    int summingPiecesArray[arrayLength];
    for (int i = 0; i < arrayLength; i++) {
        scanf("%d",&summingPiecesArray[i]);
    }
    NSMutableDictionary *iterationsDictionary = [NSMutableDictionary dictionary];
    printf("%d\n",getSummedPieces(summingPiecesArray,0,arrayLength-1,&iterationsDictionary));
    [pool drain];
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
