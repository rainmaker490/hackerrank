//@author: Varun Patel
//The Full Counting Sort
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct element {
    int inputIndex;
    char stringValue[11];
    struct element *next;
} Element;

typedef struct {
    int count;
    Element *first;
    Element *last;
} IndexedNode;

int main() {
    int array_size;
    unsigned int upperBoundCount = 100;
    scanf("%d", &array_size);
    
    IndexedNode *nodes = malloc(sizeof(IndexedNode)*upperBoundCount);
    int index;
    char inputString[11];
    for (int i = 0 ; i < array_size; i++){
        Element *current = malloc (sizeof(Element));
        scanf("%d %s",&index, current->stringValue);
        current->inputIndex = i;
        current->next = NULL;
        if (nodes[index].first == NULL) {
            nodes[index].first = current;
        } else {
            nodes[index].last->next = current;
        }
        nodes[index].last = current;
        nodes[index].count++;
    }
    
    for (int i = 0; i < upperBoundCount; i++){
        if (nodes[i].count > 0) {
            Element *current = nodes[i].first;
            while (current) {
                if(current->inputIndex < array_size/2) {
                    printf("- ");
                } else {
                    printf("%s ", current->stringValue);
                }
                current = current->next;
            }
        }
    }
    return 0;
}
