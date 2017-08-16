//@author: Varun Patel
//Staircase
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
    for (int i = 0; i < n; i++){
        //Print Spaces:
        for (int spacePrint = 0; spacePrint < n - i -1; spacePrint++) {
            printf(" ");
        }
        //Print Hashes:
        for (int hashPrint = 0; hashPrint < i+1; hashPrint++) {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
