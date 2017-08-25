//@author: Varun Patel
//Max Min
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int comparator(const void* a, const void *b){
    return *(int*)a - *(int*)b;
}

int main() {
    int n, k;
    scanf("%d\n%d", &n,&k);
    
    int *list = malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++){
        scanf("%d",&list[i]);
    }
    qsort(list,n,sizeof(int),comparator);
    //for (int i = 0; i < n; i++){
    //    printf("%d, ",list[i]);
    //}
    //printf("\n");
    int unfairness = list[n-1]-list[0];
    for (int i = 0; i <= n-k; i++){
        //printf("%d\n",n-k);
        if (list[i+k-1]-list[i] < unfairness) {
            //printf("%d:%d %d:%d\n", i,list[i],i+k,list[i+k-1]);
            unfairness = list[i+k-1]-list[i];
        }
    }
    free(list);
    printf("%d",unfairness);
    return 0;
}
