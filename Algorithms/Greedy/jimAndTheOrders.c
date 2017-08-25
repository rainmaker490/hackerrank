//@author: Varun Patel
//Jim and the Orders
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int data;
    int index;
} Orders;

int comparator (const void *a, const void *b){
    Orders *aOrder = (Orders*)a;
    Orders *bOrder = (Orders*)b;
    int aData = aOrder->data;
    int bData = bOrder->data;
    int retVal;
    if (aData - bData == 0){
        retVal = aOrder->index - bOrder->index;
    }  else {
        retVal = aData - bData;
    }
    return aData - bData;
}

/*
int indexComparator (const void *a, const void *b){
    Orders *aOrder = (Orders*)a;
    Orders *bOrder = (Orders*)b;
    int retVal;
    if (aOrder->data - bOrder->data == 0){
        retVal = aOrder->index - bOrder->index;
    }  else {
        retVal = 0;
    }
    return retVal;
} */

int main() {
    int n;
    scanf("%d",&n);
    Orders *arr = malloc(sizeof(Orders)*n);
    int input1;
    int input2;
    for (int i = 0; i < n; i++){
        scanf("%d %d",&input1, &input2);
        arr[i].data = input1+input2;
        arr[i].index = i+1;
    }
    //for (int i = 0; i < n;i++){
    //    printf("%d ", arr[i].data);
    //}
    qsort(arr,n,sizeof(Orders),comparator);
    
    for (int i = 0; i < n;i++){
        int j = i + 1;
        printf("%d ", arr[i].index);
    }
    free(arr);
    return 0;
}
