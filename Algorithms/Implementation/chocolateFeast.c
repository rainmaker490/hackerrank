//@author: Varun Patel
//Chocolate Feast
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int t;
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int c;
        int m;
        scanf("%d %d %d",&n,&c,&m);
        
        int wrappers = n/c;
        int candy = wrappers;
        
        while (wrappers >= m) {
            wrappers-=m;
            candy++;
            wrappers++;
        }
        printf("%d\n",candy);
    }
    return 0;
}
