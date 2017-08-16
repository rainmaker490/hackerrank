//@author: Varun Patel
//Breaking the Records
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d",&n);
    int *s = malloc(sizeof(int) * n);
    for(int s_i = 0; s_i < n; s_i++){
        scanf("%d",&s[s_i]);
    }
    int result_size;
    int *result = malloc(sizeof(int)*2);
    int maxScore = s[0];
    int minScore = s[0];
    int maxScoreChange = 0;
    int minScoreChange = 0;
    for (int i = 0; i < n; i++) {
        if(s[i] > maxScore){
            maxScoreChange++;
            maxScore = s[i];
        }
        
        if(s[i] < minScore){
            minScoreChange++;
            minScore = s[i];
        }
    }
    printf("%d %d", maxScoreChange, minScoreChange);
    free(s);
    free(result);
    return 0;
}
