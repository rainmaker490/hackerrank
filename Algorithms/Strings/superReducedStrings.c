//@author: Varun Patel
//Super Reduced Strings
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char* super_reduced_string(char* s, int *sizeOfReducedString){
    char *reduced = malloc(100*sizeof(char));
    int topOfStack = 0;
    for (int i = 0; i < strlen(s); i++){
        if (i == 0){
            reduced[topOfStack] = s[i];
        } else {
            if(reduced[topOfStack] == s[i]){
                topOfStack--;
            } else {
                reduced[++topOfStack] = s[i];
            }
        }
    }
    *sizeOfReducedString = topOfStack;
    return reduced;
}

int main() {
    char* s = (char *)malloc(100 * sizeof(char));
    scanf("%s", s);
    int sizeOfReducedString;
    char* reduced = super_reduced_string(s, &sizeOfReducedString);
    if (sizeOfReducedString < 0){
        printf("Empty String");
    } else {
        for(int j = 0; j <= sizeOfReducedString; j++) {
            printf("%c",reduced[j]);
        }
    }
    //printf("%s\n", sizeOfReducedString <= -1 ? "Empty String" : reduced);
    free(reduced);
    free(s);
    return 0;
}
