//@author: Varun Patel
//Cut the Tree
//Objective C Solution
#import <Foundation/Foundation.h>

/*
 3 1
 2 1
 2 3
 --------->
 6
 
 2 ---> 1
 |
 |
 v
 3
 
 Explanation :
 There are 2^3 possible sub-trees:
 {} {1} {2} {3} {1, 2} {1, 3} {2, 3} {1, 2, 3}
 But:
 the sub-trees {2} and {1,3} are not valid. {2} 
 isn't valid because it has 2 edges connecting 
 to it's complement {1,3} whereas K = 1 in the 
 sample test-case {1,3} isn't valid because, 
 well, it's not a sub-tree. 
 The nodes aren't connected.
 */

int main(int argc, const char * argv[]) {
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    
    int nodes, edgesQuery;
    scanf("%d %d", &nodes, &edgesQuery);
    NSMutableArray *edges = [NSMutableArray array];
    
    int beginning, end;
    for(int i = 0; i < nodes - 1; i++) {
        scanf("%d %d", &beginning, &end);
    }
    
    [pool drain];
    return 0;
}

