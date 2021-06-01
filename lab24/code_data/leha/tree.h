#ifndef _TREE_H_
#define _TREE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct tree Tree;

Tree *create_tree(int value);
Tree *find_node(Tree *tree, int node) ;
void add_node(Tree *tree, int node, int new);
void delete_undertree(Tree *parent);
void delete_node(Tree *parent, int node);
void delete_node_tree(Tree *tree, int node);
void destroy_tree(Tree **tree);
void print_the_tree(Tree* root, int count);
void tree_print(Tree* root);

int leaf_search(Tree *tree);

#endif