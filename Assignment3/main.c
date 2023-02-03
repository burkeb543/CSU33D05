#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


int main(){
  Tree_Node* root = NULL;
  root = malloc(sizeof(Tree_Node));
  
  
  char test[] = "FLOCCINAUCINIHILIPILIFICATION";
  root = create_bst (test);
  tree_print_sorted(root);
  root = tree_search(root , 'F');

  return 0;
}