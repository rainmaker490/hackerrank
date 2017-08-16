//@author: Varun Patel
//Simple Array Sum
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int simpleArraySum(int ar_size, int* ar) {
    int total = 0;
    for (int i = 0; i < ar_size; i++){
        total += ar[i];
    }
    return total;
}

int main() {
    int n;
    scanf("%i", &n);
    int *ar = malloc(sizeof(int) * n);
    for(int ar_i = 0; ar_i < n; ar_i++){
        scanf("%i",&ar[ar_i]);
    }
    int result = simpleArraySum(n, ar);
    free(ar);
    printf("%d\n", result);
    return 0;
}
