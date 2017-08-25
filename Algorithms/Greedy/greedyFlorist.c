//@author: Varun Patel
//Greedy Florist
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int comparator (const void* a, const void *b){
    return *(int*)b - *(int*)a;
}

int getMinimumCost(int n, int k, int* c){
    qsort(c,n,sizeof(int),comparator);
    int minimumCost = 0;
    for(int i = 0,coefficient = 0; i < n; i++){
        if (i%k == 0) {
            coefficient++;
        }
        minimumCost += (coefficient)*c[i];
    }
    return minimumCost;
}

int main() {
    int n;
    int k;
    scanf("%d %d", &n, &k);
    int *c = malloc(sizeof(int) * n);
    for(int c_i = 0; c_i < n; c_i++){
        scanf("%d",&c[c_i]);
    }
    int minimumCost = getMinimumCost(n, k, c);
    printf("%d\n", minimumCost);
    free(c);
    return 0;
}
