//@author: Varun Patel
//The Coin Change Problem
//A Non-Memoized C Solution:
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

long getWays(long n, int c_size, long int* c){
    /* Debug
     for (int i = 0; i < c_size; i++){
     printf("%li, ",c[i]);
     }
     printf("N: %li ",n);
     printf("\n");
     */
    if (n == 0) {
        return 1;
    }
    
    if (n < 0) {
        return 0;
    }
    
    long ways = 0;
    for(int i = 0; i < c_size; i++) {
        //printf("%d\n",c_size-i);
        ways += getWays(n-c[i],c_size-i,&c[i]);
        //printf("Ways:%li\n",ways);
    }
    //printf("Ways:%li\n",ways);
    return ways;
}

int main() {
    int n;
    int m;
    scanf("%d %d", &n, &m);
    long *c = malloc(sizeof(long) * m);
    //long *solutions = calloc(m,sizeof(long));
    for(int c_i = 0; c_i < m; c_i++){
        scanf("%ld",&c[c_i]);
    }
    long ways = getWays(n,m,c);
    printf("%li",ways);
    free(c);
    return 0;
}
