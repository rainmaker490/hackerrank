//@author: Varun Patel
//Angry Professor
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
        int k;
        scanf("%d %d",&n,&k);
        
        int studentArrival;
        int onTime = 0;
        int isClassCancelled = 1;
        for(int a_i = 0; a_i < n; a_i++){
            scanf("%d",&studentArrival);
            if(studentArrival <= 0){
                onTime++;
            }
            if(onTime >= k) {
                isClassCancelled = -1;
            }
        }
        if(isClassCancelled == 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
