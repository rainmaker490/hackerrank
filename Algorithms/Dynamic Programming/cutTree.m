//@author: Varun Patel
//Cut Tree
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

/*
 Adjacency List :
 1: 2
 2: 1 , 3
 3: 2
 
 [1] -> check self, how many edges? If edges == K, then count ++ …….. (1)
 
 Iterate :
 1 -> 2 (correct K count)!  **Mark 1 as visited**
 subtree 2-> count how many subtrees rooted at 2! {
	2 -> 1 **** already visited, skip
	2 -> 3 (count ++)…………………………………………………………………..(2)
 }
 
 [2] -> check self, how many edges? If edges == K, then count++.  …….. (3)
 2 -> 1 **** already visited, skip
 2 ->3 (correct K count)!  **Mark 2 as visited**
 subtree 3-> count how many subtrees rooted at 3! {
	3 -> 2 **** already visited, skip
	return 0 count (is leaf)
 }
 
 [3] -> check self, how many edges? If edges == K, then count++. …….. (4)
 Mark 3 Visited!
 3 -> 2 **** already visited, skip
 Return 1
 
 Program return 4 + 1 since {} is also a solution (See other solutions for answer to this)
 */

int cutTheTree(NSDictionary *edges) {
    [edges enumerateKeysAndObjectsWithBlock:^() {
        
    }];
    return 0;
}

int main(int argc, const char * argv[]) {
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    
    int nodes, edgesQuery;
    scanf("%d %d", &nodes, &edgesQuery);
    NSMutableDictionary *edges = [NSMutableDictionary dictionary];
    
    int beginning, end;
    for(int i = 0; i < nodes - 1; i++) {
        scanf("%d %d", &beginning, &end);
        
    }
    printf("%d",cutTheTree([edges copy]));
    
    [pool drain];
    return 0;
}

