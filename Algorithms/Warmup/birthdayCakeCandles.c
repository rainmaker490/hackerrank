//@author: Varun Patel
//Birthday Cake Candles
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int birthdayCakeCandles(int n, int ar_size, int* ar) {
    int max = ar[0];
    int maxCount = 1;
    
    for (int i = 1; i < ar_size; i++) {
        if (ar[i] > max) {
            max = ar[i];
            maxCount = 1;
        } else if (ar[i] == max) {
            maxCount++;
        }
    }
    return maxCount;
}

int main() {
    int n;
    scanf("%i", &n);
    int *ar = malloc(sizeof(int) * n);
    for(int ar_i = 0; ar_i < n; ar_i++){
        scanf("%i",&ar[ar_i]);
    }
    int result = birthdayCakeCandles(n, n, ar);
    printf("%d\n", result);
    free(ar);
    return 0;
}
