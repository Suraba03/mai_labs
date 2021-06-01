#include <stdio.h>
#include <stdlib.h>

// #include "tree.h"

typedef struct tree {
    int value;
    struct tree *right;
    struct tree *left;
} tree;

tree *tree_node_create(int value)
{
    tree *result = malloc(sizeof(treenode));
    if (result != NULL) {
        result->child = NULL;
        result->value = value;
        for () {
            result->sibling = NULL;
        }
        return result;
    } else {
        printf("Error: not enough memory to create a node\n");
        return;
    }
}

tree *tree_add_node(tree *parentv, char side, int value)
{
    tree *new_node = tree_node_create(value);
    if (side == 'r') {
        if (parentv->right == NULL) {
            parentv->right = new_node;
        }
        else {
            printf("Error: there is already a node on the right side.\nAdvice: to try choose the left branch");
        }
    }
    else {
        if (parentv->left == NULL) {
            parentv->left = new_node;
        }
        else {
            printf("Error: there is already a node on the left side.\nAdvice: try to choose the right branch");
        }
    }
    return new_node;
}

void tree_remove_node(tree *node)
{
    tree *right_child = node->right;
    tree *left_child = node->left;

    if (right_child == NULL && left_child == NULL) {
        node = NULL;
    }
    else if (right_child != NULL && left_child != NULL) {
        if (left_child->right == NULL && left_child->left == NULL && right_child->right == NULL && right_child->left == NULL) {
            node = NULL;
        }
        else if () {
            // --- the most difficult case here ---
        }
    }
    else if (right_child == NULL && left_child != NULL) {
        if (node->parent == )
    }
    else {

    }
}
