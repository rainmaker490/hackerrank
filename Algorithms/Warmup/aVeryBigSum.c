//@author: Varun Patel
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

long int aVeryBigSum(int n, int ar_size, long int* ar) {
    long int sum = ar[0];
    for(int ar_i = 1; ar_i < ar_size; ar_i++){
        sum+=ar[ar_i];
    }
    return sum;
}

int main() {
    int n;
    scanf("%i", &n);
    long int *ar = malloc(sizeof(long int) * n);
    for(int ar_i = 0; ar_i < n; ar_i++){
        scanf("%li",&ar[ar_i]);
    }
    long int result = aVeryBigSum(n, n, ar);
    printf("%ld\n", result);
    free(ar);
    return 0;
}
