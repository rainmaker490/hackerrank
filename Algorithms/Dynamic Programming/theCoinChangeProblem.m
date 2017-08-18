//@author: Varun Patel
//The Coin Change Problem
#import <Foundation/Foundation.h>

long getWays(long n, int c_size, long int* c, NSMutableDictionary **memo){
    /* Debug
     for (int i = 0; i < c_size; i++){
     printf("%li, ",c[i]);
     }
     printf("N: %li ",n);
     printf("\n");
     */
    NSString *key = [NSString stringWithFormat:@"%ld - %i",n,c_size];
    if ([*memo objectForKey:key]){
        //Debug: NSLog(@"%ld",[[*memo objectForKey:key] longLongValue]);
        return [[*memo objectForKey:key] longLongValue];
    }
    
    if (n == 0) {
        return 1;
    }
    
    if (n < 0) {
        return 0;
    }
    
    long ways = 0;
    for(int i = 0; i < c_size; i++) {
        //printf("%d\n",c_size-i);
        ways += getWays(n-c[i],c_size-i,&c[i],memo);
        //printf("Ways:%li\n",ways);
    }
    //printf("Ways:%li\n",ways);
    [*memo setObject:@(ways) forKey:key];
    //Debug: NSLog(@"%@,c_size:%i,amount:%ld",[*memo objectForKey:key],c_size,n);
    return ways;
}

int main(int argc, const char * argv[]) {
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    int n;
    int m;
    scanf("%i %i",&n,&m);
    long c[m];
    for(int c_i = 0; c_i < m; c_i++){
        scanf("%ld",&c[c_i]);
    }
    NSMutableDictionary *memo = [NSMutableDictionary dictionary];
    long ways = getWays(n,m,c,&memo);
    printf("%li",ways);
    [pool drain];
    return 0;
}
