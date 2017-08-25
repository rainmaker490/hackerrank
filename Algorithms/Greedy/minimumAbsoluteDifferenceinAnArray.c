//@author: Varun Patel
//Minimum Absolute Difference in an Array
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void merge (int **arr,int leftPivot, int middlePivot, int rightPivot){
    int left[middlePivot-leftPivot+1];
    int right[rightPivot-middlePivot];
    
    for (int i = 0, l = leftPivot; i < middlePivot-leftPivot+1; l++, i++) {
        left[i]=(*arr)[l];
    }
    
    for (int i = 0, r = middlePivot+1; i < rightPivot-middlePivot; r++, i++) {
        right[i]=(*arr)[r];
    }
    
    //for (int i = 0; i < middlePivot-leftPivot+1;i++) {
    //    printf("%d ",left[i]);
    //}
    //printf("\n");
    //for (int i = 0; i < rightPivot-middlePivot;i++) {
    //    printf("%d ",right[i]);
    //}
    //printf("\n");
    
    int i = 0;
    int j = 0;
    int k = leftPivot;
    
    while (i < middlePivot-leftPivot+1 && j < rightPivot-middlePivot) {
        if (left[i] < right[j]) {
            (*arr)[k]=left[i];
            i++;
        } else {
            (*arr)[k]=right[j];
            j++;
        }
        k++;
    }
    
    while (i < middlePivot-leftPivot+1 ) {
        (*arr)[k]=left[i];
        k++;
        i++;
    }
    
    while (j < rightPivot-middlePivot) {
        (*arr)[k]=right[j];
        k++;
        j++;
    }
}

//Merge Sort:
void mergeSort (int **arr, int leftPivot, int rightPivot) {
    if (leftPivot < rightPivot) {
        int middlePivot = (leftPivot + rightPivot) / 2 ;
        //printf ("left:%d right:%d\n",leftPivot,rightPivot);
        mergeSort(arr,leftPivot,middlePivot);
        mergeSort(arr,middlePivot+1,rightPivot);
        merge(arr,leftPivot,middlePivot,rightPivot);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int *a = malloc(sizeof(int) * n);
    for(int a_i = 0; a_i < n; a_i++){
        scanf("%d",&a[a_i]);
    }
    mergeSort(&a,0,n-1);
    
    int min = -1;
    for (int i=1; i<n; i++) {
        if (min == -1){
            min = abs(a[i-1]-a[i]);
        } else {
            if (min > abs(a[i-1]-a[i])) {
                min = abs(a[i-1]-a[i]);
            }
        }
    }
    printf("%d",min);
    return 0;
}
