//@author: Varun Patel
//The Longest Common Subsequence
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/* Sample Input:
 5 6
 1 2 3 4 1
 3 4 1 2 1 3
 ------------->
 123
 */

/*
   i
     a b c
 j   0 0 0 0
   b 0 0 1 0
   a 0 1 1
   c 0
 */

#define MAX(a,b) (((a)>(b))?(a):(b))
void printLongestCommonSubstring(int **knapsackMatrix, int *firstInputString, int *secondInputString, int sizeOfFirstString, int sizeOfSecondString) {
    //DEBUG: printf("%d ", knapsackMatrix[sizeOfSecondString][sizeOfFirstString])
    int i = sizeOfSecondString;
    int j = sizeOfFirstString;
    //DEBUG: printf("%d ", knapsackMatrix[i][j])
    while(i > 0 && j > 0) {
        if (knapsackMatrix[i][j] == knapsackMatrix[i][j-1]) {
            j--;
        }else if (knapsackMatrix[i][j] == knapsackMatrix[i-1][j-1] + 1) {
            if (knapsackMatrix[i][j] == knapsackMatrix[i-1][j]) {
                //DEBUG: printf("%d \n", knapsackMatrix[i][j]);
                i--;
            } else  {
                //DEBUG: printf("%d \n", knapsackMatrix[i][j]);
                //DEBUG: printf("%d ", firstInputString[j]);
                i--;
                j--;
            }
        }
    }
}

int longestCommonSubsequenceCount(int *firstInputString, int *secondInputString, int sizeOfFirstString, int sizeOfSecondString) {
    int **knapsackMatrix = calloc(sizeOfSecondString+1,sizeof(int*));
    knapsackMatrix[0] = calloc(sizeOfFirstString+1,sizeof(int));
    
    //PRINT-MATRIX:
    //printf("     ");
    //for (int i = 0; i < sizeOfFirstString; i++) {
    //    printf("%d ",firstInputString[i]);
    //}
    //printf("\n");
    
    //printf("   ");
    //for (int i = 0; i <= sizeOfFirstString; i++) {
    //    printf("%d ",knapsackMatrix[0][i]);
    //}
    //printf("\n");
    
    for (int i = 1; i < sizeOfSecondString; i++) {
        printf("%d, ",secondInputString[i]);
        knapsackMatrix[i] = calloc(sizeOfFirstString+1,sizeof(int));
        printf("%d ",knapsackMatrix[i][0]);
        for (int j = 1; j <= sizeOfFirstString; j++) {
            //DEBUG: printf("%d ",row[j]);
            knapsackMatrix[i][j] = MAX(knapsackMatrix[i-1][j],knapsackMatrix[i][j-1]);
            //DEBUG: printf("a:%d\n",knapsackMatrix[i-1][j]);
            //DEBUG: printf("b:%d\n",knapsackMatrix[i][j-1]);
            if (secondInputString[i - 1] == firstInputString[j - 1]) {
                knapsackMatrix[i][j] = knapsackMatrix[i-1][j-1] + 1;
            }
            //PRINT-MATRIX: printf("%d ",knapsackMatrix[i][j]);
        }
        //PRINT-MATRIX: printf("\n");
    }
    
    //printLongestCommonSubstring (knapsackMatrix,firstInputString,secondInputString,sizeOfFirstString,sizeOfSecondString);
    
    for (int j = 0; j <= sizeOfSecondString; j++){
        //free(knapsackMatrix[j]);
    }
    //free(knapsackMatrix);
    return knapsackMatrix[sizeOfFirstString][sizeOfSecondString];
}

int main() {
    int lengthOfFirstString;
    int lengthOfSecondString;
    scanf("%d %d", &lengthOfFirstString, &lengthOfSecondString);
    
    int *firstInputString = malloc(sizeof(int)*lengthOfFirstString);
    int *secondInputString = malloc(sizeof(int)*lengthOfSecondString);
    
    for (int i = 0; i < lengthOfFirstString; i++) {
        scanf("%d", &firstInputString[i]);
    }
    
    for (int i = 0; i < lengthOfSecondString; i++) {
        scanf("%d", &secondInputString[i]);
    }
    
    longestCommonSubsequenceCount(firstInputString, secondInputString, lengthOfFirstString,lengthOfSecondString);
    
    free(firstInputString);
    free(secondInputString);
    return 0;
}
