//@author: Varun Patel
//Sam and sub-strings
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

long long getSubStringTotal(char *input) {
    unsigned int MOD = 1000000007;
    long long int total = 0;
    long long int digit = 1;
    int length = strlen(input);
    for(int i = length-1; i >= 0; i--) {
        total = (total + (input[i]-'0')*digit*(i+1)) % MOD;
        //printf("Digit:%i\n",digitValue);
        //printf("%i\n",digit*(i+1)*digitValue);
        digit = (digit*10+1) % MOD;
    }
    return total;
}

int main() {
    char *input = malloc(sizeof(char)*200005);
    scanf("%s",input);
    long long output = getSubStringTotal(input);
    printf("%lld",output);
    return 0;
}
