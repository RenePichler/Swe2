#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "parser.h"
#include "arithmetic_tree.h"
#include "stack.h"

#define SIZE 100


int main(void){
    bool result;
    char string[SIZE];
//Log FIle ˆffnen
    FILE *fp = fopen("log.txt", "w");
    if(NULL == fp){
        fprintf(stderr, "Failure with FILE ptr: fp!\n");
        return -1;
    }
    FILE *fp1 = fopen("expression.txt", "r");
    if(NULL == fp1){            //error control
        fprintf(fp, "Failure with FILE ptr: fp1!\n");
        fprintf(stderr, "Failure with FILE ptr: fp1!\n");
        return -2;
    }
//Einlesen
//get data from expression file
    fgets(string, SIZE-1, fp1); //get string from file
    fprintf(fp, "Start parsing of %s\n\n", string);
//Verarbeitung

    fprintf(stdout, "Start parsing of %s\n\n", string);
    s = string;
    result = expression(fp);
    if(result == false){
        fprintf(fp, "Fehler kein ar. Ausdruck gef.\n");
        return -3;
    }
    else if(result == true){
        fprintf(fp, "Erfolgreich Ausdruck gefunden\n");
        fprintf(stdout, "Ausdruck gef.\n");
    }
//Erstellen des Stack
    HEAD *inputstack = create_stack();
    if(NULL == inputstack){
        fprintf(fp, "failure with create_stack()! | -4\n");
        fprintf(stderr, "failure with create_stack()!\n");
        return -4;
    }
    HEAD *operatorstack = create_stack();
    if(NULL == operatorstack){
        fprintf(fp, "failure with create_stack! | -5\n");
        fprintf(stderr, "failure with create_stack!\n");
        return -5;
    }
    HEAD *outputstack = create_stack();
    if(NULL == outputstack){
        fprintf(fp, "failure with create_stack()! | -6\n");
        fprintf(stderr, "failure with create_stack()! | -6\n");
        return -6;
    }
//Bef¸llen des imp Stack
    fill_stack(inputstack, string);
    emptystack(inputstack);
//Erstellen des Baums
    printf("\nTEST\n");
    fputs(string, stdout);
    char *test = searchroot(string);
    NODE* root = create_node(*test, NULL);
    printf("\n\n%c\n", root->elem);
//Ausgabe
    fprintf(stdout, "\nRPN - reversed polnish notation\n\n");
    print_postorder(root);
    fprintf(stdout, "\nIFN - infix notation\n\n");
    print_inorder(root);
//Fp schlieﬂen
    fclose(fp);
    fclose(fp1);
    return 0;
}
