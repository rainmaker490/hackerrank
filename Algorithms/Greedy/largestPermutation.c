//@author: Varun Patel
//Largest Permutation
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int arrayLength,maxSwaps;
    scanf("%d %d", &arrayLength,&maxSwaps);
    int *inputArray = malloc(sizeof(int)*arrayLength);
    int *parrallelInputArray = malloc(sizeof(int)*(arrayLength+1));
    for(int i = 0; i < arrayLength; i++){
        scanf("%d",&inputArray[i]);
        parrallelInputArray[inputArray[i]]=i;
    }
    
    int i = 0;
    while(maxSwaps > 0 && i < arrayLength){
        if(inputArray[i] != arrayLength-i) {
            inputArray[parrallelInputArray[arrayLength - i]] = inputArray[i];
            parrallelInputArray[inputArray[i]] = parrallelInputArray[arrayLength - i];
            inputArray[i] = arrayLength - i;
            parrallelInputArray[arrayLength - i] = i;
            maxSwaps--;
        }
        i++;
    }
    
    for(int i = 0; i < arrayLength; i++){
        printf("%d ", inputArray[i]);
    }
    free(inputArray);
    free(parrallelInputArray);
    return 0;
}


