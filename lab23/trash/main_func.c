// C программа для проверки, все ли листья на одном уровне
#include <stdio.h>
#include <stdlib.h>

  
// Узел двоичного дерева

struct Node

{

    int data;

    struct Node *left, *right;

};

  
// Вспомогательная функция для выделения нового узла дерева

struct Node* newNode(int data)

{

    struct Node* node = (struct Node*) malloc(sizeof(struct Node));

    node->data = data;

    node->left = node->right = NULL;

    return node;

}

  
/* Рекурсивная функция, которая проверяет, все ли листья находятся на одном уровне */

int checkUtil(struct Node *root, int level, int *leafLevel)
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

bool check(struct Node *root)

{

   int level = 0, leafLevel = 0;

   return checkUtil(root, level, &leafLevel);

}

  
// Программа драйвера для проверки вышеуказанной функции

int main()

{

    // Давайте создадим дерево, показанное в третьем примере

    struct Node *root = newNode(12);

    root->left = newNode(5);

    root->left->left = newNode(3);

    root->left->right = newNode(9);

    root->left->left->left = newNode(1);

    root->left->right->left = newNode(1);

    if (check(root))

        printf("Leaves are at same level\n");

    else

        printf("Leaves are not at same level\n");

    getchar();

    return 0;

}