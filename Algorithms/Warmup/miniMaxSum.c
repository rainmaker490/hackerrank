//@author: Varun Patel
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    int *arr = malloc(sizeof(int) * 5);
    long int sum = 0;
    for(int arr_i = 0; arr_i < 5; arr_i++){
        scanf("%d",&arr[arr_i]);
        sum += arr[arr_i];
    }
    
    long int min = arr[0];
    long int max = arr[0];
    
    for (int i = 1 ; i < 5; i++){
        min = arr[i] < min ? arr[i] : min ;
        max = arr[i] > max ? arr[i] : max ;
    }
    
    printf("%ld %ld", sum-max, sum-min);
    free(arr);
    return 0;
}
