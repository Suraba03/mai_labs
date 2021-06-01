#ifndef _TREE_H_
#define _TREE_H_

#include <stdio.h>
#include <stdlib.h>

typedef int TreeItem;
typedef struct _tree Tree;

Tree *tree_create(TreeItem value);
Tree *tree_add_node(Tree *parent, TreeItem value);
void tree_node_print(TreeItem value, int indent);
void tree_print(Tree *t);

#endif // _TREE_H_
