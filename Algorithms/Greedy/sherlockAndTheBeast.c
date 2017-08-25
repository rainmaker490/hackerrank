//@author: Varun Patel
//Sherlock and the Beast
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void sherlockPrint (int five, int three, int n) {
    if (5*three+3*five != n){
        printf("-1\n");
        return;
    }
    
    for (int i = 0; i < five*3; i++) {
        printf("5");
    }
    for (int i = 0 ; i < three*5; i++){
        printf("3");
    }
    printf("\n");
}

int main(){
    int t;
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int n;
        scanf("%d",&n);
        int numberOfFives = n/3;
        while (numberOfFives > 0) {
            if (((n -(numberOfFives*3)) % 5) == 0){
                break;
            } else {
                numberOfFives--;
            }
        }
        sherlockPrint(numberOfFives,(n-(numberOfFives*3))/5,n);
    }
    return 0;
}
