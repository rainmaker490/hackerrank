//@author: Varun Patel
//Cats and a Mouse
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int q;
    scanf("%d",&q);
    for(int a0 = 0; a0 < q; a0++){
        int x;
        int y;
        int z;
        scanf("%d %d %d",&x,&y,&z);
        if(abs(z-x) < abs(y-z)){
            printf("Cat A");
        } else if(abs(z-y) < abs(x-z)){
            printf("Cat B");
        } else {
            printf("Mouse C");
        }
        printf("\n");
    }
    return 0;
}
