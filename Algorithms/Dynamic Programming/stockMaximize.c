//@author: Varun Patel
//Stock Maximize
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/*
 3
 3
 5 3 2
 3
 1 2 100
 4
 1 3 1 2
 ----------
 0
 197
 3
 */

int main() {
    int queries;
    scanf("%d", &queries);
    for(int a0 = 0; a0 < queries; a0++){
        int n;
        scanf("%d", &n);
        int *arr = malloc(sizeof(int) * n);
        for (int arr_i = 0; arr_i < n; arr_i++) {
            scanf("%i",&arr[arr_i]);
        }
        int currentMax = arr[n-1];
        long long currentProfit = 0;
        for(int i = n-1; i >=0; i--){
            if(currentMax < arr[i]){
                currentMax = arr[i];
            }
            currentProfit += (currentMax - arr[i]);
        }
        printf("%lld\n",currentProfit);
        free(arr);
    }
    return 0;
}
