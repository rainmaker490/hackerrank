//@author: Varun Patel
//Picking Numbers
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n;
    scanf("%d",&n);
    int a[100] = {0};
    int input;
    for(int a_i = 0; a_i < n; a_i++){
        scanf("%d",&input);
        a[input]++;
    }
    
    int max = 0;
    for(int i = 0; i < 99; i++){
        if(a[i] + a[i+1] > max){
            max = a[i] + a[i+1];
        }
    }
    printf("%d",max);
    return 0;
}
