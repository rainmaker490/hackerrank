//@author: Varun Patel
//Divisible Sum Pairs
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int divisibleSumPairs(int k, int ar_size, int* ar) {
    int i = 0;
    int divisiblePairs = 0;
    while (i < ar_size) {
        for(int j = i+1; j < ar_size; j++){
            if((ar[i] + ar[j]) % k == 0){
                divisiblePairs++;
            }
        }
        i++;
    }
    return divisiblePairs;
}

int main() {
    int n;
    int k;
    scanf("%i %i", &n, &k);
    int *ar = malloc(sizeof(int) * n);
    for(int ar_i = 0; ar_i < n; ar_i++){
        scanf("%i",&ar[ar_i]);
    }
    int result = divisibleSumPairs(k, n, ar);
    printf("%d\n", result);
    free(ar);
    return 0;
}
