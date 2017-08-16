//@author: Varun Patel
//Sock Merchant
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%i", &n);
    int ar[100] = {0};
    int temp;
    int count = 0;
    for(int ar_i = 0; ar_i < n; ar_i++){
        scanf("%i", &temp);
        ar[temp]++;
        if(ar[temp] % 2 == 0){
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
