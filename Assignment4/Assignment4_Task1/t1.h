#ifndef T1_H_
#define T1_H_

struct node {
  char vertex;
  struct node* next;
};

typedef struct Graph{
    //TODO
  int numVertices;
  int* visited_dfs;
  int* visited_bfs;
  struct node** adjLists;
} Graph;


Graph* create_graph(int num_nodes); // creates a graph with num_nodes nodes, assuming nodes are stored in alphabetical order (A, B, C..)
void add_edge(Graph *g, int from, int to); // adds a directed edge
void bfs(Graph* g, int origin); //implements breath first search and prints the results
void dfs(Graph* g, int origin); //implements depth first search and prints the results
void delete_graph(Graph* g); // deletes the graph

#endif