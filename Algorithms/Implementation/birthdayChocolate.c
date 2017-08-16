//@author: Varun Patel
//Birthday Chocolate
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int solve(int n, int s_size, int* s, int d, int m){
    int combinations = 0;
    for(int i = 0; i <= n - m; i++) {
        int total = s[i];
        for (int j = i+1; j < i+m; j++){
            total+=s[j];
        }
        
        if(total == d){
            combinations++;
        }
    }
    return combinations;
}

int main() {
    int n;
    scanf("%d", &n);
    int *s = malloc(sizeof(int) * n);
    for(int s_i = 0; s_i < n; s_i++){
        scanf("%d",&s[s_i]);
    }
    int d;
    int m;
    scanf("%d %d", &d, &m);
    int result = solve(n, n, s, d, m);
    printf("%d\n", result);
    free(s);
    return 0;
}
