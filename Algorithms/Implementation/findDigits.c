//@author: Varun Patel
//Find Digits
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
        scanf("%d",&n);
        int numberOfDivisibleDigits = 0;
        int digit;
        int temp_containter = n;
        while (temp_containter!=0){
            digit = temp_containter%10;
            if (digit != 0){
                if(n % digit == 0){
                    numberOfDivisibleDigits++;
                }
            }
            temp_containter = temp_containter/10;
        }
        printf("%d\n", numberOfDivisibleDigits);
    }
    return 0;
}
