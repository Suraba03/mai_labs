#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	int data;
	struct tree *son;
	struct tree *bro;
} Tree;

Tree *create_tree(int value) 
{
	Tree *tree = (Tree *)malloc(sizeof(Tree));
	tree->data = value;
	tree->son = NULL;
	tree->bro = NULL;
	return tree;
}

Tree *find_node(Tree *tree, int node) 
{
	if (tree == NULL) {
        return NULL;
    }
    if (tree->data == node) {
        return tree;
    }
    Tree *finder = NULL;
    if (tree->son) {
        finder = find_node(tree->son, node);
        if (finder != NULL) {
           return finder;
        }
    }
    if (tree->bro) {
        finder = find_node(tree->bro, node);
        if (finder != NULL) {
            return finder;
        }
    }

}

void add_node(Tree *tree, int node, int new) 
{
	Tree *node_value = find_node(tree, node);
	if (node_value->son == NULL) {
		node_value->son = create_tree(new);
	} else {
		node_value = node_value->son;
		while (node_value->bro != NULL) {
			node_value = node_value->bro;
		}
		node_value->bro = create_tree(new);
	}
}

void delete_undertree(Tree *parent) 
{
	if (parent == NULL) {
        return;
    } else {
        if (parent->son) {
            parent = parent->son;
        } else {
            return;
        }
        if (parent->son) {
            delete_undertree(parent->son);
        }
        Tree* next = parent;
        Tree* prev = NULL;
        while (next->bro) {
            prev = next;
            next = next->bro;
            if (next->son) {
                delete_undertree(next->son);
            }
            free(prev);
        }
        free(next);
    }
}

void delete_node(Tree *tree, int value) 
{
	if (tree != NULL) {
        if (tree->son != NULL) {
            if (tree->son->data == value) {
                Tree* prev = tree->son;
                tree->son = tree->son->bro;
                free(prev);
                prev = NULL;
            } else {
                delete_node(tree->son, value);
            }
        }
        if (tree->bro != NULL) {
            if (tree->bro->data == value) {
                Tree* prev = tree->bro;
                tree->bro = tree->bro->bro;
                free(prev);
                prev = NULL;
            } else {
                delete_node(tree->bro, value);
            }
        }
    }
}

void delete_node_tree(Tree *tree, int node) 
{
	Tree *parent = find_node(tree, node);
	delete_undertree(parent);
	delete_node(tree, node);
}

void destroy_tree(Tree **tree) 
{
	if ((*tree)->son) {
        destroy_tree(&((*tree)->son));
    }
    if ((*tree)->bro) {
        destroy_tree(&((*tree)->bro));
    }
    free(*tree);
    *tree = NULL;
}

void print_the_tree(Tree* root, int count)
{
    if (root != NULL) {
        for (int i = 0; i < count; i++) {
            printf(" ");
        }
        printf("%d", root->data);
        printf("\n");
    }
    if (root->son != NULL) {
        print_the_tree(root->son, count + 2);
    }
    if (root->bro != NULL) {
        print_the_tree(root->bro, count);
    }
}

void tree_print(Tree* root)
{
    if (root != NULL) {
        print_the_tree(root, 0);
    } else {
        printf("Дерево не существует\n");
    }
}

int leaf_search(Tree *tree) 
{
	int c = 0;
	if (tree->son == NULL) {
		c = 1;
		return c;
	}
	if (tree->son){
		c+= leaf_search(tree->son);
	}
	if (tree->son->bro) {
		Tree *now = tree->son->bro;
		while (now != NULL) {
			c+= leaf_search(now);
			now = now->bro;
		} 
	}
	return c;
}

