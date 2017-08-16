//@author: Varun Patel
//Between Two Sets
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int gcd(int a, int b) {
    while (b > 0){
        int temp = b;
        b = a%b;
        a=temp;
    }
    return a;
}
int getTotalX(int a_size, int* a, int b_size, int* b){
    int totalX = 0;
    int lcm = a[0];
    for (int a_i = 1 ; a_i < a_size; a_i++){
        lcm = a[a_i] * lcm / gcd(a[a_i],lcm);
    }
    
    int gcdX = b[0];
    for (int b_i = 1; b_i < b_size; b_i++) {
        gcdX = gcd(gcdX,b[b_i]);
    }
    
    for (int i = lcm, j = 2; i <= gcdX; i=lcm*j,j++){
        if(gcdX%i == 0){
            totalX++;
        }
    }
    
    return totalX;
}

int main() {
    int n;
    int m;
    scanf("%d %d", &n, &m);
    int *a = malloc(sizeof(int) * n);
    for(int a_i = 0; a_i < n; a_i++){
        scanf("%d",&a[a_i]);
    }
    int *b = malloc(sizeof(int) * m);
    for(int b_i = 0; b_i < m; b_i++){
        scanf("%d",&b[b_i]);
    }
    int total = getTotalX(n,a,m,b);
    printf("%d\n", total);
    free(a);
    free(b);
    return 0;
}
