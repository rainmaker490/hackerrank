//@author: Varun Patel
//The Coin Change Problem
//Objective C Solution
#import <Foundation/Foundation.h>

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

BOOL dpAbbreviation(char* a, char*b, int indexA, int indexB, int sizeA, int sizeB, NSMutableDictionary **memo) {
    NSString *key = [NSString stringWithFormat:@"%i-%i",indexA,indexB];
    if ([*memo objectForKey:key]){
        return [[*memo objectForKey:key] boolValue];
    }
    
    if (indexA == sizeA && indexB == sizeB) {
        return YES;
    }
    
    if (indexA == sizeA && indexB < sizeB) {
        //printf("2\n");
        return NO;
    }
    
    if (indexA < sizeA && indexB == sizeB){
        BOOL isTransformable = false;
        if(a[indexA]-'a' >= 0 && a[indexA]-'a' <= 25){
            isTransformable = dpAbbreviation(a,b,indexA+1,indexB,sizeA,sizeB,memo);
        }
        [*memo setObject:@(isTransformable) forKey:key];
        return isTransformable;
    }
    
    //printf("A:%c,B:%c\n",toupper(a[indexA]), b[indexB]);
    if (a[indexA]-'a' >= 0 && a[indexA]-'a' <= 25) {
        bool isTransformable = dpAbbreviation(a,b,indexA+1,indexB,sizeA,sizeB,memo);
        if (a[indexA] - 'a' == b[indexB] - 'A'){
            isTransformable = isTransformable || dpAbbreviation(a,b,indexA+1,indexB+1,sizeA,sizeB,memo);
        }
        [*memo setObject:@(isTransformable) forKey:key];
        return isTransformable;
    } else {
        bool isTransformable = NO;
        if(a[indexA] == b[indexB]) {
            isTransformable = isTransformable || dpAbbreviation(a,b,indexA+1,indexB+1,sizeA,sizeB,memo);
        }
        [*memo setObject:@(isTransformable) forKey:key];
        return isTransformable;
    }
}

int abbreviation(char* a, char* b, int sizeA, int sizeB, NSMutableDictionary **memo) {
    return dpAbbreviation(a,b,0,0,sizeA,sizeB,memo);
}

int main(int argc, const char * argv[]) {
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    int queries;
    scanf("%i",&queries);
    for(int i = 0; i < queries; i++) {
        NSMutableDictionary *memo = [NSMutableDictionary dictionary];
        char a[512000];
        char b[512000];
        scanf("%s",a);
        scanf("%s",b);
        BOOL result = abbreviation(a,b,strlen(a), strlen(b), &memo);
        result ? printf("YES") : printf("NO") ;
        printf("\n");
    }
    [pool drain];
    return 0;
}
