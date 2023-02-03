#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"


Tree_Node *new_node(Tree_Node** root, char data){
    *root = (Tree_Node *)malloc(sizeof(Tree_Node));
    (*root)->left_child = NULL;
    (*root)->right_child = NULL;
    (*root)->data = data;
    return (*root);
}

void tree_insert(struct Tree_Node** root, char data){
    // TODO
    Tree_Node *temp = NULL;

    // if root is null then create new node in tree
    if (*root == NULL){
        new_node(&temp, data);
        *root = temp;
        return;
    }

    // if char is less than or equal to the root insert at left child
    if (data <= (*root)->data){
        tree_insert(&(*root)->left_child, data);
    }
    // else insert at right child
    else {
        tree_insert(&(*root)->right_child, data);
    }
 }


Tree_Node* create_bst (char data[]){
    // TODO
    Tree_Node *root;
    int i = 0;
    while (data[i] != '\0'){ // add chars to tree until end of string reached
      tree_insert(&root, data[i]);
      i++;
    }
    return root;
}

Tree_Node* tree_search(Tree_Node* root, char data){
    //TODO
   Tree_Node *temp;

    if (root == NULL){
        temp = NULL;
    }
    else{
        if (root->data == data){
            temp = root;
        }
        else{
            if (root->data < data){
                temp = tree_search(root->right_child, data);
            }
            else{
                temp = tree_search(root->left_child, data);
            }
        }
    }
    return temp;
}

void tree_print_sorted(Tree_Node* root){
    //TODO
     if(root!=NULL){ 
        tree_print_sorted(root->left_child); // visiting left child
        printf("%c", root->data); // printing data at root
        tree_print_sorted(root->right_child);// visiting right child
    }
}


void tree_delete(Tree_Node* root){
    //TODO
    if (root!=NULL) {
        tree_delete(root->left_child);
        tree_delete(root->right_child);
        free(root);
    }
}
