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

char* longestCommonSubsequence(char *firstInputString, char *secondInputString) {
    int **knapsackMatrix = calloc(strlen(secondInputString),sizeof(int*));
    knapsackMatrix[0] = calloc(firstInputString,sizeof(int));
    for (int i = 1; i <= firstInputString; i++) {
        
    }
    return NULL;
}

int main() {
    int lengthOfFirstString;
    int lengthOfSecondString;
    scanf("%d %d", &lengthOfFirstString, &lengthOfSecondString);
    
    char *firstInputString = malloc(sizeof(char)*lengthOfFirstString+1);
    char *secondInputString = malloc(sizeof(char)*lengthOfSecondString+1);
    scanf("%s", firstInputString);
    scanf("%s", secondInputString);
    
    printf("%s", longestCommonSubsequence(firstInputString, secondInputString));
    
    free(firstInputString);
    free(secondInputString);
    return 0;
}
