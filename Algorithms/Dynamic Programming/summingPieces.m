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

/* INPUT / OUTPUT
 3
 1 3 6
 ------->
 73
 */

long long int getSummedPieces(int *summingPiecesArray,int startIndex, int endIndex, NSMutableDictionary **memo) {
    if (startIndex > endIndex) {
        //printf("Iterator  %d\n",startIndex-endIndex);
        return 0;
    }
    
    if ([*memo objectForKey:[NSString stringWithFormat:@"%d",startIndex]]) {
        //printf("VALUE: %lli\n",[[*memo objectForKey:[NSString stringWithFormat:@"%d",startIndex]] longLongValue]);
        return [[*memo objectForKey:[NSString stringWithFormat:@"%d",startIndex]] longLongValue];
    }
    
    int groups = 1;
    long long int currentSum = 0;
    //printf("StartIndex:%d,EndIndex:%d\n",startIndex,endIndex);
    int loopCount = 1;
    while (groups - 1 < endIndex - startIndex + 1) {
        //printf("Groups:%d, End:%d, Start:%d\n",groups - 1,endIndex,startIndex+1);
        long long int groupedSum = 0;
        for (int i = startIndex; i <= startIndex+groups-1; i++){
            groupedSum+=summingPiecesArray[i];
            groupedSum = groupedSum % 1000000007;
        }
        //printf("GroupedSum %lli\n",groupedSum);
        /*
        for (int i = startIndex; i <= startIndex+groups-1; i++){
            printf("%d, ",summingPiecesArray[i]);
        }
        printf("\n");
        */
        long long int subSum = getSummedPieces(summingPiecesArray,startIndex+groups,endIndex,memo);
        //printf("GroupedSum%d\n",groupedSum);
        //printf("GroupedTotal%d\n",groupedSum*groups);
        subSum += 1000000007;
        currentSum += subSum % 1000000007;
        currentSum = currentSum % 1000000007;
        long long int loopCount = endIndex - (startIndex + groups) ;
        //printf("LoopCount   %d\n",loopCount);
        if (loopCount < 0) {
            loopCount++;
            //printf("LoopCount   %d\n",loopCount);
            //printf("Loop Count Less Than 0\n");
        }
        //printf("GroupedSum: %lli ,,,, LoopCount   %lli \n",groupedSum,loopCount);
        long long int pow = 1;
        for (int i = 1; i <= loopCount; i++) {
            pow *= 2;
            pow = pow % 1000000007;
        }
        int sum = (groupedSum * pow * groups) % 1000000007;
        currentSum +=(sum+1000000007);
        currentSum = currentSum % 1000000007;
        //printf("CURRENTSUM   %d\n",currentSum);
        //printf("Iterator  %d\n",loopCount);
        //printf("GroupedSum%d\n",groupedSum);
        groups++;
    }
    [*memo setObject:@(currentSum) forKey:[NSString stringWithFormat:@"%d",startIndex]];
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
    NSMutableDictionary *memo = [NSMutableDictionary dictionary];
    printf("%lli\n",getSummedPieces(summingPiecesArray,0,arrayLength-1, &memo));
    [pool drain];
    return 0;
}
