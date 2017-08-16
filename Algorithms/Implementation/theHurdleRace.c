//@author: Varun Patel
//The Hurdle Race
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n;
    int k;
    scanf("%d %d",&n,&k);
    
    int boost = 0;
    int input;
    for(int height_i = 0; height_i < n; height_i++){
        scanf("%d",&input);
        if (input - k > boost) {
            boost = input - k;
        }
    }
    printf("%d",boost);
    return 0;
}
