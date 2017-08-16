//@author: Varun Patel
//Plus Minus
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int arr_i = 0; arr_i < n; arr_i++){
        scanf("%d",&arr[arr_i]);
    }
    int positiveCount = 0;
    int negativeCount = 0;
    int zeroCount = 0;
    
    for (int arr_y = 0; arr_y < n; arr_y++){
        if(arr[arr_y] == 0){
            zeroCount++;
        } else if (arr[arr_y] > 0) {
            positiveCount++;
        } else if (arr[arr_y] < 0) {
            negativeCount++;
        }
    }
    float positive = (float)positiveCount/(float)n;
    float negative = (float)negativeCount/(float)n;
    float zero = (float)zeroCount/(float)n;
    printf("%f\n", positive);
    printf("%f\n", negative);
    printf("%f\n", zero);
    return 0;
}
