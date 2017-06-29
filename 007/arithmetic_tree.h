#ifndef ARITHMETIC_TREE_H_INCLUDED
#define ARITHMETIC_TREE_H_INCLUDED

typedef struct node{                    //Node Struckt
    char elem;
    struct node *left;
    struct node *right;
} NODE;

NODE *create_node(char, NODE*);    //Stack Funktionen
void print_inorder(NODE*);
void print_postorder(NODE*);
void print_preorder(NODE*);
char *searchroot(char*);


#endif
