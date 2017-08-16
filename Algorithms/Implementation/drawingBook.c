//@author: Varun Patel
//Drawing Book
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int solve(int n, int p){
    int frontCount = p/2;
    int backCount = n/2 - p/2;
    return frontCount > backCount ? backCount : frontCount;
}

int main() {
    int n;
    scanf("%d", &n);
    int p;
    scanf("%d", &p);
    int result = solve(n, p);
    printf("%d\n", result);
    return 0;
}
