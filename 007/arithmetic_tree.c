#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "arithmetic_tree.h"

//Erstellen des Baums
NODE *create_node(char elem, NODE *node){
    if(NULL == node){
        node = (NODE*)malloc(sizeof(NODE));
        if(NULL == node){
            fprintf(stderr, "Fehler mit malloc()\n");
            return NULL;
        }

        node->elem = elem;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

//Inorder Ausgaben
void print_inorder(NODE *node){
    if(node->left != NULL){
        print_inorder(node->left);
    }
    if(node != NULL){
        fprintf(stdout, "%c", node->elem);
    }
    if(node->right != NULL){
        print_inorder(node->right);
    }
}
//Preorder Ausgeben
void print_preorder(NODE *node){
    if(node != NULL){
        fprintf(stdout, "%c", node->elem);
    }
    if(node->left != NULL){
        print_preorder(node->left);
    }
    if(node->right != NULL){
        print_preorder(node->right);
    }
}
//Postorder ausgeben
void print_postorder(NODE *node){
    if(node->left != NULL){
        print_postorder(node->left);
    }
    if(node->right != NULL){
        print_postorder(node->right);
    }
    if(node != NULL){
        fprintf(stdout, "%c", node->elem);
    }
}



//Durchsuchen
char *searchroot(char *exp){
    int cnt = 0;
    while(*exp != '\0'){
        if(*exp == '('){
            cnt++;
        }
        else if(*exp == ')'){
            cnt--;
        }
        else if((*exp == '+' || *exp == '-' || *exp == '/' || *exp == '*' ) && cnt == 0){
            return exp;
        }
        exp++;
    }
    return NULL;
}
