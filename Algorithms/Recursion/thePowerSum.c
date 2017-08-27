//@author: Varun Patel
//The Power Sum
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int getCombinations(int total, int exponent, int currentBase) {
    int remainder = total - pow(currentBase,exponent);
    
    if (remainder == 0) {
        return 1;
    }
    
    if (remainder < 0) {
        return 0;
    }
    
    return getCombinations(remainder,exponent,currentBase+1) + getCombinations(total,exponent,currentBase+1);
}

int main() {
    int total;
    scanf("%d",&total);
    int exponent;
    scanf("%d",&exponent);
    
    int combinations = getCombinations(total,exponent,1);
    printf("%d",combinations);
    return 0;
}
