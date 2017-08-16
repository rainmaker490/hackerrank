#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void refreshScore (int ai, int bi, int *a, int *b) {
    if (ai > bi) {
        (*a)+=1;
    } else if (ai < bi) {
        (*b)+=1;
    }
}

int* solve(int a0, int a1, int a2, int b0, int b1, int b2, int *result_size){
    *result_size = 2;
    int a = 0;
    int b = 0;
    refreshScore(a0,b0,&a,&b);
    refreshScore(a1,b1,&a,&b);
    refreshScore(a2,b2,&a,&b);
    int *result = (int*)malloc(2 * sizeof(int));
    result[0] = a;
    result[1] = b;
    return result;
}

int main() {
    int a0;
    int a1;
    int a2;
    scanf("%d %d %d", &a0, &a1, &a2);
    int b0;
    int b1;
    int b2;
    scanf("%d %d %d", &b0, &b1, &b2);
    int result_size;
    int* result = solve(a0, a1, a2, b0, b1, b2, &result_size);
    for(int result_i = 0; result_i < result_size; result_i++) {
        if(result_i) {
            printf(" ");
        }
        printf("%d", result[result_i]);
    }
    puts("");
    
    return 0;
}
