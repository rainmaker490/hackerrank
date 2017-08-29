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

char* findSubstring(int **knapsackMatrix, char *firstInputString, char *secondInputString) {
    char *longestCommonSubString = malloc(sizeof(char)*knapsackMatrix[strlen(secondInputString)][strlen(firstInputString)]);
    
    
    
    return longestSubstring;
}

char* longestCommonSubsequence(char *firstInputString, char *secondInputString) {
    int **knapsackMatrix = calloc(strlen(secondInputString)+1,sizeof(int*));
    knapsackMatrix[0] = calloc(firstInputString+1,sizeof(int));
    for (int i = 1; i <= strlen(secondInputString); i++) {
        int *row = calloc(firstInputString+1,sizeof(int));
        knapsackMatrix[i] = row;
        for (int j = 1; j <= strlen(secondInputString); j++) {
            row[j] = MAX(knapsackMatrix[i-1][j],knapsackMatrix[j-1][i])
            if (firstInputString[i - 1] == secondInputString[j - 1]) {
                row[j]++;
            }
        }
    }
    char *longestSubstring = findSubstring(knapsackMatrix,firstInputString,secondInputString);
    for (int j = 0; j <= strlen(secondInputString); j++){
        free(knapsackMatrix[j]);
    }
    free(knapsackMatrix);
    return longestSubstring;
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
