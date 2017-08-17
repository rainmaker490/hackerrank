//@author: Varun Patel
//Viral Advertising
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int input;
    scanf("%d", &input);
    int totalPeople = 5;
    int sum = 0;
    for (int i = 0; i < input; i++) {
        totalPeople = totalPeople/2;
        sum += totalPeople;
        totalPeople = totalPeople*3;
    }
    printf("%d", sum);
    return 0;
}
