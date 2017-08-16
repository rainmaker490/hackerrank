//@author: Varun Patel
//Grading Students
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void solve(int grades_size, int** grades){
    for (int i = 0; i < grades_size; i++){
        int roundedDifference = 5 - (grades[0][i] % 5);
        
        if(!(grades[0][i] < 38)) {
            if (roundedDifference < 3) {
                grades[0][i] += roundedDifference;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int *grades = malloc(sizeof(int) * n);
    for(int grades_i = 0; grades_i < n; grades_i++){
        scanf("%d",&grades[grades_i]);
    }
    int result_size;
    solve(n, &grades);
    for(int result_i = 0; result_i < n; result_i++) {
        if(result_i) {
            printf("\n");
        }
        printf("%d", grades[result_i]);
    }
    puts("");
    free(grades);
    return 0;
}
