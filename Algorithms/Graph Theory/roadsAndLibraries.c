//@author: Varun Patel
//Roads and Libraries
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

struct Vertex {
    int edge;
    struct Vertex *next;
};

struct AdjacencyListArray {
    struct Vertex *head;
    struct Vertex *tail;
};

void insert(int city, struct Vertex **head, struct Vertex **tail) {
    struct Vertex *newVertex = malloc(sizeof(struct Vertex));
    newVertex->edge = city;
    newVertex->next = NULL;
    
    if (*head == NULL){
        *head = newVertex;
        *tail = newVertex;
        //printf("City:%d Edge %d\n", city, head->edge);
        return;
    }
    
    /*
    struct Vertex *current = *head;
    //printf("Head %d", head->edge);
    while (current->next != NULL){
        current = current->next;
    } */
     
    struct Vertex *currentTail = *tail;
    currentTail->next = newVertex;
    *tail = newVertex;
}

int dfs(int heads_i, struct AdjacencyListArray *heads, int **visited){
    int count = 0;
    //printf("dfs, heads_i:%d\n", heads_i);
    
    /* Debug:
    for (int i = 0; i < 3; i++){
        printf("%d ", *visited[i]);
    } */
    
    (*visited)[heads_i] = 1;
    
    struct Vertex *current = heads[heads_i].head;
    while(current){
        if((*visited)[current->edge] == 0){
            count += 1 + dfs(current->edge, heads,visited);
        }
        current = current->next;
    }
    
    return count;
}

int main() {
    int q;
    scanf("%i", &q);
    for(int a0 = 0; a0 < q; a0++){
        int n;
        int m;
        long int x;
        long int y;
        scanf("%i %i %li %li", &n, &m, &x, &y);
        
        //Custom Variables:
        struct AdjacencyListArray *heads = malloc(sizeof(struct AdjacencyListArray)*n);
        int *visited = calloc(n, sizeof(int));
        int connectedComponents = 0;
        int roads = 0;
        
        //Init Heads to NULL
        for (int i = 0; i < n; i++){
            heads[i].head = NULL;
        }
        
        for(int a1 = 0; a1 < m; a1++){
            int city_1;
            int city_2;
            scanf("%i %i", &city_1, &city_2);
            
            //Insert into Adjacency List:
            insert(city_1-1, &heads[city_2-1].head,&heads[city_2-1].tail);
            insert(city_2-1, &heads[city_1-1].head,&heads[city_1-1].tail);
        }
        
        /*
        //Debug :
        for(int i = 0; i < n; i++){
            printf("Adjacency List %d:\n", i);
            struct Vertex *current = heads[i].head;
            if (current != NULL){
                while (current != NULL){
                    printf("%d ", current->edge);
                    current = current->next;
                }
            }
            printf("\n\n");
        } */
        
        for (int heads_i = 0; heads_i < n; heads_i++){
            if (visited[heads_i] == 0){
                roads += dfs(heads_i, heads, &visited);
                connectedComponents++;
            }
        }
        
        long int totalCost = 0;
        if (x > y) {
            totalCost = y*roads + x*connectedComponents;
        } else {
            totalCost = x * n;
        }
        
        //printf("Connected Components %d\n", connectedComponents);
        //printf("Roads %d\n", roads);
        //printf("x %li\n",x);
        //printf("y %li\n",y);
        printf("%li\n",totalCost);
    }
    return 0;
}
