//@author: Varun Patel
//Beautiful Days at the Movies
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int getReverse (int numberToBeReversed){
    int reversedNumber = 0;
    while (numberToBeReversed != 0){
        int lastDigit = numberToBeReversed % 10;
        reversedNumber = reversedNumber*10 + lastDigit;
        numberToBeReversed = numberToBeReversed / 10;
    }
    return reversedNumber;
}

int main() {
    int startDay;
    int endDay;
    int mod;
    scanf("%d %d %d", &startDay, &endDay, &mod);
    
    int beautifulDays = 0;
    for (int i = startDay; i <= endDay; i++){
        int reverse = getReverse(i);
        if(abs(i - reverse) % mod == 0){
            beautifulDays++;
        }
    }
    printf("%d", beautifulDays);
    return 0;
}
