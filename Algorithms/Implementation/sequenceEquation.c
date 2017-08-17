//@author: Varun Patel
//Sequence Equation
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d\n", &n);
    int *p = malloc(51*sizeof(int));
    int distinctNumber;
    for(int i = 0; i < n; i++){
        scanf("%d",&distinctNumber);
        p[distinctNumber] = i + 1;
    }
    
    for(int i = 0; i < n; i++){
        printf("%d\n",p[p[i+1]]);
    }
    free(p);
    return 0;
}
