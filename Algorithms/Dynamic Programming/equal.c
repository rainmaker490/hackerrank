//@author: Varun Patel
//Equal
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/* Algorithm / Example :
2 (7) 7 7 7 7
7 7 (12) 12 12 12
12 12 12 (19) 19 19
17 17 17 (19) 24 24
19 19 19 (19) 26 26
 */

/* Input :
1
4
2 2 3 7 
 */

int getMinimumIterations(int **distributedCandies, int index, int arrayLength) {
    
}

int main() {
    int queries;
    scanf("%d",&queries);
    for (int i = 0; i < queries; i++) {
        int arrayLength;
        scanf("%d", &arrayLength);
        int *distributedCandies = malloc(arrayLength*sizeof(int));
        int minimumIterations = getMinimumIterations(&distributedCandies,0,arrayLength);
        printf("%d\n",minimumIterations);
        free(distributedCandies);
    }
    return 0;
}
