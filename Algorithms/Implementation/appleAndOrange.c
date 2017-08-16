//@author: Varun Patel
//Apple and Orange
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int s;
    int t;
    scanf("%d %d",&s,&t);
    int a;
    int b;
    scanf("%d %d",&a,&b);
    int m;
    int n;
    scanf("%d %d",&m,&n);
    int *apple = malloc(sizeof(int) * m);
    for(int apple_i = 0; apple_i < m; apple_i++){
        scanf("%d",&apple[apple_i]);
    }
    int *orange = malloc(sizeof(int) * n);
    for(int orange_i = 0; orange_i < n; orange_i++){
        scanf("%d",&orange[orange_i]);
    }
    
    int apples = 0;
    int oranges = 0;
    
    for(int apple_i = 0; apple_i < m; apple_i++) {
        int x_position = a + apple[apple_i];
        if (x_position >= s && x_position <= t){
            apples++;
        }
    }
    
    for(int orange_i = 0; orange_i < n; orange_i++) {
        int x_position = b + orange[orange_i];
        if (x_position >= s && x_position <= t){
            oranges++;
        }
    }
    printf("%d\n%d", apples,oranges);
    free(apple);
    free(orange);
    return 0;
}
