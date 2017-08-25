//@author: Varun Patel
//Permuting Two Arrays
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int ascendingComparator(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int descendingComparator(const void *a, const void *b){
    return *(int*)b - *(int*)a;
}

int main() {
    int queries;
    scanf("%d",&queries);
    for (int i = 0; i < queries; i++){
        int arr_length, k;
        scanf("%d %d", &arr_length, &k);
        int *arr_a = malloc(sizeof(int)*arr_length);
        int *arr_b = malloc(sizeof(int)*arr_length);
        for(int j = 0; j < arr_length; j++){
            scanf("%d",&arr_a[j]);
        }
        for(int j = 0; j < arr_length; j++){
            scanf("%d",&arr_b[j]);
        }
        qsort(arr_a,arr_length,sizeof(int),ascendingComparator);
        qsort(arr_b,arr_length,sizeof(int),descendingComparator);
        int isPermutable = 1;
        for(int j = 0; j < arr_length && isPermutable == 1; j++){
            if(arr_a[j]+arr_b[j] < k){
                printf("NO");
                isPermutable = -1;
                break;
            }
        }
        if (isPermutable == 1) {
            printf("YES");
        }
        printf("\n");
        
        free(arr_a);
        free(arr_b);
    }
    return 0;
}
