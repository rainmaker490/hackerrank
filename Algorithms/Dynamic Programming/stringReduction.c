//@author: Varun Patel
//String Reduction
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int stringReduction(char a[]) {
    int alphabetArray[3] = {0};
    for (int i = 0 ; i < strlen(a); i++){
        alphabetArray[a[i]-'a']++;
    }
    
    for (int i = 0 ; i < 3; i++){
        if (alphabetArray[i] == strlen(a)) {
            return strlen(a);
        }
    }
    
    if ((alphabetArray[0]%2==0 && alphabetArray[1]%2==0 && alphabetArray[2]%2==0) || (alphabetArray[0]%2==1 && alphabetArray[1]%2==1 && alphabetArray[2]%2==1)){
        return 2;
    }
    return 1;
}

int main() {
    int res, t, i;
    scanf("%d",&t);
    char a[100001];
    for (i=0;i<t;i++) {
        scanf("%s",a);
        res=stringReduction(a);
        printf("%d\n",res);
    }
    return 0;
}
