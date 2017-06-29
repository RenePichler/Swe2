#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

typedef struct node{               //Elemente
    char character;
    char str[7];
    struct node *right;
    struct node *left;
} NODE;                             //Typedef

typedef struct root{                //Baum
    char str[6];
    int len;
    NODE *left;
    NODE *right;
} ROOT;                             //Typedef

NODE *create_binarytree_NODE(char, const char*, **NODE);  //Baumstruktur erstellen
NODE *create_morsecode_tree(void);                       //Fixer baum mit den Morsecode
char *write_morsecode(const char*);                      //String zu morsecode umsetzen
int read_morsecode(const char*, NODE*);                  //String in zeichen zerteilen
void print_morsecode_tree(NODE*);                        //Morsecode ausgeben
NODE *search_character(const char*, NODE*);              //zeichen suchen

#endif // BINARYTREE_H_INCLUDED
