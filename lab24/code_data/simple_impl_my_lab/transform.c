#include "tree.h"
#include "transform.h"
#include <math.h>


int list_count(Tree root)
{
    int result;
    if ((root->left == NULL) && (root->right == NULL)) {
        result = 1;
    } else {
        result = 0;
    } if (root->left) {
        result += list_count(root->left);
    } if (root->right) {
        result += list_count(root->right);
    } 
    return result;
}


