//@author: Varun Patel
//Service Lane
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n;
    int t;
    scanf("%d %d",&n,&t);
    int width[n];
    for(int width_i = 0; width_i < n; width_i++){
        scanf("%d",&width[width_i]);
    }
    for(int a0 = 0; a0 < t; a0++){
        int i;
        int j;
        scanf("%d %d",&i,&j);
        
        int min = width[i];
        for (int k = i+1; k <= j; k++){
            if (min > width[k]){
                min = width[k];
            }
        }
        printf("%d\n",min);
    }
    return 0;
}
