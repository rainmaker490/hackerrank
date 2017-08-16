//@author: Varun Patel
//Migratory Birds
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int migratoryBirds(int n, int* ar) {
    int totalTypes[5] = {0};
    
    for(int i = 0; i < n; i++){
        totalTypes[ar[i]-1]++;
    }
    
    int maxIndex = 0;
    for (int i = 1; i < 5; i++){
        if(totalTypes[i] > totalTypes[maxIndex]){
            maxIndex = i;
        }
    }
    //printf("%d %d %d %d %d\n", totalTypes[0], totalTypes[1], totalTypes[2], totalTypes[3], totalTypes[4]);
    return maxIndex+1; //bird id = index+1
}

int main() {
    int n;
    scanf("%i", &n);
    int *ar = malloc(sizeof(int) * n);
    for(int ar_i = 0; ar_i < n; ar_i++){
        scanf("%i",&ar[ar_i]);
    }
    int result = migratoryBirds(n, ar);
    printf("%d\n", result);
    free(ar);
    return 0;
}
