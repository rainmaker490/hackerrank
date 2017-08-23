//@author: Varun Patel
//Abbreviation
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdbool.h>

/*
 1
 daBcd
 ABC
 ---->YES
 
 1
 KXzQ
 K
 ---->NO
 */

bool dpAbbreviation(char* a, char*b, int indexA, int indexB) {
    if (indexA <= strlen(a) && indexB == strlen(b)) {
        for (int i = indexA; i < strlen(a); i++){
            if (isupper(a[i])){
                //printf("1\n");
                return false;
            }
        }
        return true;
    }
    
    if (indexA == strlen(a) && indexB < strlen(b)) {
        //printf("2\n");
        return false;
    }
    
    //printf("A:%c,B:%c\n",toupper(a[indexA]), b[indexB]);
    if (!isupper(a[indexA])) {
        bool isTransformable = dpAbbreviation(a,b,indexA+1,indexB);
        if (a[indexA] - 'a' == b[indexB] - 'A'){
            isTransformable = isTransformable || dpAbbreviation(a,b,indexA+1,indexB+1);
        }
        return isTransformable;
    } else {
        bool isTransformable = false;
        if(a[indexA] == b[indexB]) {
            isTransformable = isTransformable || dpAbbreviation(a,b,indexA+1,indexB+1);
        }
        return isTransformable;
    }
}

int abbreviation(char* a, char* b) {
    return dpAbbreviation(a,b,0,0);
}

int main() {
    int q;
    scanf("%i", &q);
    for(int a0 = 0; a0 < q; a0++){
        char* a = (char *)malloc(512000 * sizeof(char));
        scanf("%s", a);
        char* b = (char *)malloc(512000 * sizeof(char));
        scanf("%s", b);
        int result_size;
        bool result = abbreviation(a, b);
        printf(!result ? "NO" : "YES");
        printf("\n");
        free(a);
        free(b);
    }
    return 0;
}
