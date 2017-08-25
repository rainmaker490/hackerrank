//@author: Varun Patel
//Mark and Toys
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int comparator (const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int maximumToys(int prices_size, int* prices, int k) {
    qsort(prices,prices_size,sizeof(int),comparator);
    
    int toyCount = 0;
    int i = 0;
    while (k > 0 && i < prices_size){
        k-=prices[i];
        toyCount++;
        i++;
    }
    return k < 0 ? toyCount - 1 : toyCount;
}

int main() {
    int n;
    int k;
    scanf("%i %i", &n, &k);
    int *prices = malloc(sizeof(int) * n);
    for (int prices_i = 0; prices_i < n; prices_i++) {
        scanf("%i",&prices[prices_i]);
    }
    int result = maximumToys(n,prices,k);
    printf("%d\n", result);
    free(prices);
    return 0;
}
