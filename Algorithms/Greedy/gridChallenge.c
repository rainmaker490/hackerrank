//@author: Varun Patel
//Grid Challenge
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
    return ( *(char*)a - *(char*)b );
}

int main() {
    int testCases;
    scanf("%d", &testCases);
    for (int i = 0; i < testCases; i++){
        int squareMatrixWidth = 0;
        scanf("%d",&squareMatrixWidth);
        int *alphabetTable = calloc(squareMatrixWidth,sizeof(int));
        char row[squareMatrixWidth];
        int isValid = 1;
        for (int j = 0; j < squareMatrixWidth; j++){
            scanf("%s ",row);
            qsort(row, squareMatrixWidth, sizeof(char), cmpfunc);
            if (isValid == 1){
                for (int v = 0; v < squareMatrixWidth && isValid == 1; v++){
                    if (alphabetTable[v] <= row[v]-'a'){
                        alphabetTable[v] = row[v]-'a';
                    } else {
                        //printf("hi %d, hi %d\n",alphabetTable[v],row[v]);
                        //printf("v %d\n",v);
                        isValid = -1;
                    }
                }
            }
        }
        free(alphabetTable);
        printf(isValid == -1 ? "NO" : "YES");
        printf("\n");
    }
    return 0;
}
