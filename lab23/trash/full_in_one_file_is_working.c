#include <stdio.h>
#include <stdlib.h>

// #include "tree.h"

typedef struct tree {
    int value;
    struct tree *right;
    struct tree *left;
} tree;

tree *tree_node_create(int crt_value)
{
    tree *result = malloc(sizeof(tree));

    if (result != NULL) {
        result->right = NULL;
        result->left = NULL;
        result->value = crt_value;
        return result;
    } else {
        printf("Error: not enough memory to create a node\n");
        return NULL;
    }
}

tree *search(tree *root, int srch_value) // srch_value is the searching value
{
    if (root == NULL || root->value == srch_value) { //  if root->value == srch_value then the element found or we reached the null node (reached the leaf's child)
        return root;
    }
    else if (srch_value > root->value) { // if srch_value greater then root->value, so we will search the right subtree
        return search(root->right, srch_value);
    }
    else { // if srch_value smaller then root->value, so we will search the left subtree
        return search(root->left, srch_value);
    }
}

/*bool is_same_depth(tree *root)
{
    if (root == NULL) {
        // There is a leaf ;)
    }
    else if (srch_value > root->value) {
        return search(root->right, srch_value);
    }
    else {
        return search(root->left, srch_value);
    }
}*/

void print_tree(tree *root, int level)
{
    if (root != NULL) {
        print_tree(root->left, level + 1);

        for (int i = 0; i < level; i++) {
            printf("\t");
        }
        printf("%d\n\n", root->value);
        print_tree(root->right, level + 1);
    }
}


// tree_find_minimum function
// call the function, while the 1st condition is false (root (root->left from last call of func) == NULL).
// When 1st condition will become true,
// program will return current root value.

tree *tree_find_minimum(tree *root)
{
    if (root == NULL) {
        return NULL;
    }
    else if (root->left != NULL) {
        return tree_find_minimum(root->left);
    }
    return root;
}

// tree_add_node function
// Assign function value to right (left) child's node, while the 1st condition is false.
// When 1st condition will become true,
// I'll create new node in place of the last tree_add_node function's output.

tree *tree_add_node(tree *root, int add_value)
{
    if (root == NULL) {
        return tree_node_create(add_value);
    }
    else if (add_value > root->value) {
        root->right = tree_add_node(root->right, add_value);
    }
    else {
        root->left = tree_add_node(root->left, add_value);
    }
    return root;
}

tree *tree_delete_node(tree *root, int del_value)
{
    if (root == NULL) {
        printf("Error: a node with value = %d does not exist in the tree\n", del_value);
        return NULL;
    }
    if (del_value > root->value) {
        root->right = tree_delete_node(root->right, del_value);
    }
    else if (del_value < root->value) {
        root->left = tree_delete_node(root->left, del_value);
    }
    else {

        // no children
        if (root->right == NULL && root->left == NULL) {
            free(root);
            return NULL;
        }

        // one child
        else if (root->right == NULL || root->left == NULL) {
            tree *temp;

            if (root->left == NULL) {
                temp = root->right;
            } else {
                temp = root->left;
            }
            free(root);
            return temp;
        }

        // two children
        else {
            tree *temp = tree_find_minimum(root->right);
            root->value = temp->value;
            root->right = tree_delete_node(root->right, temp->value);
        }
    }
    return root;
}

void inorder(tree *root)
{
    if (root != NULL) { // checking if the root is not null
        inorder(root->left); // visiting left child
        printf(" %d ", root->value); // printing data at root
        inorder(root->right); // visiting right child
    }
}

int checkUtil(tree *root, int level, int *leafLevel)
{
    // Базовый вариант
    if (root == NULL) { 
        return 1;
    }
    // Если встречается листовой узел
    if (root->left == NULL && root->right == NULL)
    {
        // Когда листовой узел найден впервые
        if (*leafLevel == 0)
        {
            *leafLevel = level; // Установить уровень первого найденного листа
            return 1;
        }

        // Если это не первый листовой узел, сравниваем его уровень с
        // уровень первого листа
        return (level == *leafLevel);
    }

    // Если этот узел не листовой, рекурсивно проверяем левое и правое поддеревья
    return checkUtil(root->left, level+1, leafLevel) && checkUtil(root->right, level+1, leafLevel);

}

  
/* Основная функция, чтобы проверить, все ли листья находятся на одном уровне.

   В основном использует checkUtil () */

int check(tree *root)
{
   int level = 0, leafLevel = 0;
   return checkUtil(root, level, &leafLevel);
}

int main(int argc, char const *argv[])
{
    /*
                   20
                 /    \
                /      \
               5       30
             /   \     /\
            /     \   /  \
           1      15 25  40
                /          \
               /            \
              9             45
            /   \          /
           /     \        /
          7      12      42
    */
    tree *root;
    root = tree_node_create(20);
    tree_add_node(root,5);
    tree_add_node(root,1);
    tree_add_node(root,15);
    // tree_add_node(root,9);
    // tree_add_node(root,7);
    // tree_add_node(root,12);
    tree_add_node(root,30);
    tree_add_node(root,25);
    // tree_add_node(root,40);
    // tree_add_node(root, 45);
    // tree_add_node(root, 42);

    // print_tree(root, 0);
    // printf("\n\n\n\n\n\n\n");

    // root = tree_delete_node(root, 1);
    /*
                   20
                 /    \
                /      \
               5       30
                 \     /\
                  \   /  \
                  15 25   40
                /           \
               /             \
              9              45
            /   \           /
           /     \         /
          7      12       42

    */
    /*print_tree(root, 0);
    printf("\n");
    root = tree_delete_node(root, 40);*/
    /*
                   20
                 /    \
                /      \
               5       30
                 \     /\
                  \   /  \
                  15 25  45
                 /       /
                /       /
               9       42
             /   \
            /     \
           7      12

    */
    /*print_tree(root, 0);
    printf("\n");
    root = tree_delete_node(root, 45);*/
    /*
                   20
                 /    \
                /      \
               5       30
                 \     /\
                  \   /  \
                  15 25  42
                 /
                /
               9
             /   \
            /     \
           7      12
    */
    /*print_tree(root, 0);
    printf("\n");
    root = tree_delete_node(root, 9);

    root = tree_delete_node(root, 156);

    print_tree(root, 0);
    putchar('\n');*/
    /*
                   20
                 /    \
                /      \
               5       30
                 \     /\
                  \   /  \
                  15 25  42
                 /
                /
               12
             /
            /
           7
    */

    // printf("\n%d\n", tree_find_minimum(search(root, 20))->value);
    if (check(root)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }   
    return 0;
}

/*
















*/
