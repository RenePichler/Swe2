#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binarytree.h"
#define M_MAX 2048         //Maximale länge der Nachricht


NODE *create_binarytree_NODE(char c, const char *string, NODE **node){
        if(NULL == *node){ //Fehlerüberprüfung
        node = (NODE*)malloc(sizeof(NODE));                         //Speicher reservieren mit malloc
        if(NULL == *node){  //Fehlerüberprüfung
            fprintf(stderr, "Fehler mit malloc\n");
            return NULL;
        }
        node->character = c;
        int len = strlen(string);
        strncpy(node->str, string, len+1);                          // Kopieren des Strings
        node->left = NULL;                                          //Pointer initialisieren
        node->right = NULL;
    }

    else if(*string == '.'){                                       //Anlegen der morsebaumstruktur
        string++;                                                  //Links sind "."
        node->left = create_binarytree_NODE(c, string, &(*node)->left);
    }

    else if(*string == '-'){
        string++;                                                   //Rechts sind "-"
        node->right = create_binarytree_NODE(c, string, &(*node)->right);
    }
    return *(node);                                                    //Zurückgeben des Pointers
}

/**function (2) hard coded binary-tree*/
NODE *create_morsecode_tree(void){                                    /*binary tree with morse-code*/
    /*0-25 = A-Z    26-35 = 1-9     36-38 = +, /, =*/
    char *morsecode[] = {".-", "-...","-.-.", "-..", ".", "..-.", "--.", "....", "..",".---", "-.-", ".-..", "--", "-.","---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.", "-..-.", "-...-"};
    NODE *root;
    root = create_binarytree_NODE('#', "START", root);
    /*error control*/
    if(NULL != root){
                                                            //Linker Teilbaum
        create_binarytree_NODE('E', morsecode[4], &root);
        create_binarytree_NODE('I', morsecode[8], &root);
        create_binarytree_NODE('A', morsecode[0], &root);
        create_binarytree_NODE('S', morsecode[18], &root);
        create_binarytree_NODE('U', morsecode[20], &root);
        create_binarytree_NODE('R', morsecode[17], &root);
        create_binarytree_NODE('W', morsecode[22], &root);
        create_binarytree_NODE('H', morsecode[7], &root);
        create_binarytree_NODE('V', morsecode[21], &root);
        create_binarytree_NODE('F', morsecode[5], &root);
        create_binarytree_NODE('$', "..--$", &root);
        create_binarytree_NODE('L', morsecode[11], &root);
        create_binarytree_NODE('$', ".-.-$", &root);
        create_binarytree_NODE('P', morsecode[15], &root);
        create_binarytree_NODE('J', morsecode[9], &root);
        create_binarytree_NODE('5', morsecode[31], &root);
        create_binarytree_NODE('4', morsecode[30], &root);
        create_binarytree_NODE('3', morsecode[29], root);
        create_binarytree_NODE('2', morsecode[28], root);
        create_binarytree_NODE('+', morsecode[36], root);
        create_binarytree_NODE('1', morsecode[27], root);
                                                                //Rechter Teilbaum
        create_binarytree_NODE('T', morsecode[19], root);
        create_binarytree_NODE('N', morsecode[13], root);
        create_binarytree_NODE('M', morsecode[12], root);
        create_binarytree_NODE('D', morsecode[3], root);
        create_binarytree_NODE('K', morsecode[10], root);
        create_binarytree_NODE('G', morsecode[6], root);
        create_binarytree_NODE('O', morsecode[14], root);
        create_binarytree_NODE('B', morsecode[1], root);
        create_binarytree_NODE('X', morsecode[23], root);
        create_binarytree_NODE('C', morsecode[2], root);
        create_binarytree_NODE('Y', morsecode[24], root);
        create_binarytree_NODE('Z', morsecode[25], root);
        create_binarytree_NODE('Q', morsecode[16], root);
        create_binarytree_NODE('$', "---.$", root);
        create_binarytree_NODE('$', "----$", root);
        create_binarytree_NODE('6', morsecode[32], root);
        create_binarytree_NODE('=', morsecode[38], root);
        create_binarytree_NODE('/', morsecode[37], root);
        create_binarytree_NODE('7', morsecode[33], root);
        create_binarytree_NODE('8', morsecode[34], root);
        create_binarytree_NODE('9', morsecode[35], root);
        create_binarytree_NODE('0', morsecode[26], root);
        return root;
    }
    return NULL;
}

//Übersetzung eines String in einen Morsecode
char *write_morsecode(const char *string){
    if(NULL == string){
        fprintf(stderr, "failure with string pointer!\n");
        return NULL;
    }
        //Array mit den Morsecodes
    char *morsecode[] = {".-$", "-...$","-.-.$", "-..$", ".$", "..-.$", "--.$", "....$", "..$",".---$", "-.-$", ".-..$", "--$", "-.$","---$", ".--.$", "--.-$", ".-.$", "...$", "-$", "..-$", "...-$", ".--$", "-..-$", "-.--$", "--..$", "-----$", ".----$", "..---$", "...--$", "....-$", ".....$", "-....$", "--...$", "---..$", "----.$", ".-.-.$", "-..-.$", "-...-$"};
    char *message = calloc(M_MAX, sizeof(char));

    if(NULL == message){
        fprintf(stderr, "failure with message pointer!\n");
        return NULL;
    }
    /
    while(*string != '\0'){
        if(*string == 'A' || *string == 'a'){
            strncat(message, morsecode[0], 4);
        }
        else if(*string == 'B' || *string == 'b'){
            strncat(message, morsecode[1], 6);
        }
        else if(*string == 'C' || *string == 'c'){
            strncat(message, morsecode[2], 6);
        }
        else if(*string == 'D' || *string == 'd'){
            strncat(message, morsecode[3], 5);
        }
        else if(*string == 'E' || *string == 'e'){
            strncat(message, morsecode[4], 3);
        }
        else if(*string == 'F' || *string == 'f'){
            strncat(message, morsecode[5], 6);
        }
        else if(*string == 'G' || *string == 'g'){
            strncat(message, morsecode[6], 5);
        }
        else if(*string == 'H' || *string == 'h'){
            strncat(message, morsecode[7], 6);
        }
        else if(*string == 'I' || *string == 'i'){
            strncat(message, morsecode[8], 4);
        }
        else if(*string == 'J' || *string == 'j'){
            strncat(message, morsecode[9], 6);
        }
        else if(*string == 'K' || *string == 'k'){
            strncat(message, morsecode[10], 5);
        }
        else if(*string == 'L' || *string == 'l'){
            strncat(message, morsecode[11], 6);
        }
        else if(*string == 'M' || *string == 'm'){
            strncat(message, morsecode[12], 4);
        }
        else if(*string == 'N' || *string == 'n'){
            strncat(message, morsecode[13], 4);
        }
        else if(*string == 'O' || *string == 'o'){
            strncat(message, morsecode[14], 5);
        }
        else if(*string == 'P' || *string == 'p'){
            strncat(message, morsecode[15], 6);
        }
        else if(*string == 'Q' || *string == 'q'){
            strncat(message, morsecode[16], 6);
        }
        else if(*string == 'R' || *string == 'r'){
            strncat(message, morsecode[17], 5);
        }
        else if(*string == 'S' || *string == 's'){
            strncat(message, morsecode[18], 5);
        }
        else if(*string == 'T' || *string == 't'){
            strncat(message, morsecode[19], 3);
        }
        else if(*string == 'U' || *string == 'u'){
            strncat(message, morsecode[20], 5);
        }
        else if(*string == 'V' || *string == 'v'){
            strncat(message, morsecode[21], 6);
        }
        else if(*string == 'W' || *string == 'w'){
            strncat(message, morsecode[22], 5);
        }
        else if(*string == 'X' || *string == 'x'){
            strncat(message, morsecode[23], 6);
        }
        else if(*string == 'Y' || *string == 'y'){
            strncat(message, morsecode[24], 6);
        }
        else if(*string == 'Z' || *string == 'z'){
            strncat(message, morsecode[25], 6);
        }
        else if(*string == '0'){
            strncat(message, morsecode[26], 7);
        }
        else if(*string == '1'){
            strncat(message, morsecode[27], 7);
        }
        else if(*string == '2'){
            strncat(message, morsecode[28], 7);
        }
        else if(*string == '3'){
            strncat(message, morsecode[29], 7);
        }
        else if(*string == '4'){
            strncat(message, morsecode[30], 7);
        }
        else if(*string == '5'){
            strncat(message, morsecode[31], 7);
        }
        else if(*string == '6'){
            strncat(message, morsecode[32], 7);
        }
        else if(*string == '7'){
            strncat(message, morsecode[33], 7);
        }
        else if(*string == '8'){
            strncat(message, morsecode[34], 7);
        }
        else if(*string == '9'){
            strncat(message, morsecode[35], 7);
        }
        else if(*string == '+'){
            strncat(message, morsecode[36], 7);
        }
        else if(*string == '/'){
            strncat(message, morsecode[37], 7);
        }
        else if(*string == '='){
            strncat(message, morsecode[38], 7);
        }
        else{
            strncat(message, "$", 2);
        }
        string++;            //Zähler erhöhen
    }
    message[strlen(message)+1] = '\0'; //terminate string
    return message;         //Pointer zurück geben
}

//String in Char zerlegen
int read_morsecode(const char *string, NODE *root){

    if(NULL == string){
        fprintf(stderr, "failure with string!\n");
        return -1;
    }

    while(*string != '\0'){
        search_character(string, root);
        while(*string != '$'){  //search next char
            string++;
        }
        string++;
    }
    return 0;   //Wenn erfolgreich 0 zurück geben
}

//Ausgabe des Baums auf Stdout
void print_morsecode_tree(NODE *node){                                // In order Ausgabe
    if(node->left != NULL){
        print_morsecode_tree(node->left);
    }
    if(node != NULL){
        fprintf(stdout, "Pointer [%p], Character: [%c]\n",node, node->character);
    }
    if(node->right != NULL){
        print_morsecode_tree(node->right);
    }
}

//ZEichen suchen
NODE *search_character(const char *string, NODE* root){
    if(NULL == string || NULL == root){
        fprintf(stderr, "failure with node pointer!\n");
        return NULL;
    }
    if(*string == '$'){         //Bis $
        fprintf(stdout," ");
        return root;
    }
    NODE *node;
    if(*string == '.'){         //wenn . dann links
        node = root->left;
        string++;
    }
    else if(*string == '-'){    //sonst rechts
        node = root->right;
        string++;
    }
    while(*string != '$'){
        if(*string == '.'){     //links
            node = node->left;
        }
        else if(*string == '-'){
            node = node->right;
        }
        string++;               //nächstes zeichen
    }
    fprintf(stdout, "%c", node->character); //Ausgabe
    return node;
}
