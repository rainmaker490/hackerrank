//@author: Varun Patel
//Kingdom Division
//Objective C Solution
#import <objc/objc.h>
#import <objc/Object.h>
#import <Foundation/Foundation.h>

@interface Edge : NSObject
@property(assign) int start;
@property(assign) int end;
@end

@implementation Edge
- (instancetype) initWithStart:(int)start andEnd:(int)end {
    self = [super init];
    if (self) {
        _start = start;
        _end = end;
    }
    return self;
}
@end

int getCombinations(NSArray *edges){
    __block int ways = 0;
    NSMutableDictionary *hasPartner = [NSMutableDictionary dictionary];
    [edges enumerateObjectsUsingBlock:^(Edge *edge, NSUInteger idx, BOOL * _Nonnull stop) {
        if([hasPartner objectForKey:@(edge.start)]) {
            int current = [[hasPartner objectForKey:@(edge.start)] integerValue];
            current++;
            [hasPartner setObject:@(current) forKey:@(edge.start)];
        } else {
            [hasPartner setObject:@(1) forKey:@(edge.start)];
        }
        
        if([hasPartner objectForKey:@(edge.end)]){
            int current = [[hasPartner objectForKey:@(edge.end)] integerValue];
            current++;
            [hasPartner setObject:@(current) forKey:@(edge.end)];
        } else {
            [hasPartner setObject:@(1) forKey:@(edge.end)];
        }
    }];
    
    [edges enumerateObjectsUsingBlock:^(Edge *edge, NSUInteger idx, BOOL * _Nonnull stop) {
        //NSLog(@"EdgeStart: %li, Edge end: %li\n",edge.start,edge.end);
        //NSLog(@"%li, %li\n",[[hasPartner objectForKey:@(edge.start)] integerValue],[[hasPartner objectForKey:@(edge.end)] integerValue]);
        if([[hasPartner objectForKey:@(edge.start)] integerValue] > 1 && [[hasPartner objectForKey:@(edge.end)] integerValue] > 1) {
            ways++;
        }
    }];
    return ((ways + 1) * 2 );
}

int main(int argc, const char * argv[]) {
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    NSMutableArray *edges = [NSMutableArray array];
    int numberOfEdges;
    scanf("%i",&numberOfEdges);
    
    int start;
    int end;
    for (int i = 0; i < numberOfEdges-1; i++) {
        Edge *edge = [[Edge alloc] initWithStart:start andEnd:end];
        scanf("%i %i", &start, &end);
        edge.start = start;
        edge.end = end;
        [edges addObject:edge];
    }
    int combinations = getCombinations([edges copy]);
    printf("%i",combinations);
    [pool drain];
    return 0;
}
