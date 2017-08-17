//@author: Varun Patel
//Save the Prisoner!
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    int t;
    scanf("%d", &t);
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int m;
        int s;
        scanf("%d %d %d", &n, &m, &s);
        int poisonCandy = (s-1 + m)%n ;
        printf("%d\n", poisonCandy == 0 ? n : poisonCandy);
    }
    return 0;
}
