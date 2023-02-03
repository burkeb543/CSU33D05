#include "t1.h"
#include <stdio.h>
#include <stdlib.h>


// Create a node
struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

Graph* create_graph(int num_nodes){
  
  printf("DFS: ");
  Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = num_nodes;

  graph->adjLists = malloc(num_nodes * sizeof(struct node*));

  graph->visited_dfs = malloc(num_nodes * sizeof(int));
  graph->visited_bfs = malloc(num_nodes * sizeof(int));

  int i;
  for (i = 0; i < num_nodes; i++) {
    graph->adjLists[i] = NULL;
    graph->visited_dfs[i] = 0;
    graph->visited_bfs[i] = 0;
  }
  return graph;
}


void add_edge(Graph *g, int from, int to){
  struct node* newNode = createNode(to);
  newNode->next = g->adjLists[from];
  g->adjLists[from] = newNode;

  // Add edge from dest to src
  newNode = createNode(from);
  newNode->next = g->adjLists[to];
  g->adjLists[to] = newNode;
}


int letters[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int i = 0;


void dfs(Graph* g, int origin){
  i++;
  if (i < g->numVertices){
    printf("%c  ", letters[origin] + 'A');
  }
  else{
    printf("%c", letters[origin] + 'A');
  }
  struct node* adjList = g->adjLists[origin];
  struct node* temp = adjList;

  g->visited_dfs[origin] = 1;
  
  while (temp != NULL) {
    int connectedVertex = temp->vertex;

    if (g->visited_dfs[connectedVertex] == 0) {
      dfs(g, connectedVertex);
    }
    temp = temp->next;
  }

}

#define SIZE 50

struct queue {
  int items[SIZE];
  int front;
  int rear;
};

// Create a queue
struct queue* createQueue() {
  struct queue* q = malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  return q;
}

// Check if the queue is empty
int isEmpty(struct queue* q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

// Adding elements into queue
void enqueue(struct queue* q, int value) {
  if (q->rear == SIZE - 1)
    {}
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}

// Removing elements from queue
int dequeue(struct queue* q) {
  int item;
  if (isEmpty(q)) {
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      q->front = q->rear = -1;
    }
  }
  return item;
}

int j = 0;

void bfs(Graph* g, int origin){
  printf(" \nBFS  ");
  struct queue* q = createQueue();

  g->visited_bfs[origin] = 1;
  enqueue(q, origin);

  while (!isEmpty(q)) {
    int currentVertex = dequeue(q);
    j++;
    if (j < g->numVertices){
      printf("%c  ", letters[currentVertex] + 'A');
    }
    else{
      printf("%c ", letters[currentVertex] + 'A');
    }

    struct node* temp = g->adjLists[currentVertex];

    while (temp) {
      int adjVertex = temp->vertex;

      if (g->visited_bfs[adjVertex] == 0) {
        g->visited_bfs[adjVertex] = 1;
        enqueue(q, adjVertex);
      }
      temp = temp->next;
    }
  }
  printf("\n");
}


void delete_graph(Graph* g){

}
