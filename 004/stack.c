#include <stdio.h>
#include <stdlib.h>
#include "head.h"

/*Einen neuen Stack erstellen*/
STACK_H *create_stack(void){                            /*Erstellen einer leeren Liste*/
    STACK_H *stack;                                     /*Pointer f�r dequeue
    */
    stack = (STACK_H*)malloc(sizeof(STACK_H));
    if(NULL == stack){                                  /*Fehler�berpr�fung*/
        fprintf(stderr, "failure with malloc!\n");
        return NULL;
    }
    stack->next = NULL;                                 /*Pointer auf das erste Element*/
    stack->last = NULL;                                 /*Pointer auf das letzte Element*/
    stack->len = 0;                                     /*L�nge*/
    return stack;                                       /*R�ckgabe Pointer auf Header der Liste*/
}

/*Funktioon Push zum einf�gen in den Stack*/
ELEM *push(STACK_H *header){                            /*create new element*/
    int i = 0;                                          /*int value*/
    char c, choice;                                     /*character and buffer for choice*/
    ELEM *element;                                      /*Pointer auf Element*/
    do{                                                 /*Wert einlesen*/
        printf("What do you want to do? insert new int(i) or new char(c), your choice: ");
        scanf("%c", &choice);
    } while(getchar() != '\n');                         /*bis \n*/
    if(choice == 'i' || choice == 'I'){                 /*Wenn ein Int wert engegeben werden will*/
        element = (ELEM*)malloc(sizeof(ELEM));
        if(NULL == element){                            /*fehler�berp. bei malloc*/
            fprintf(stderr, "failure with malloc!\n");
            return NULL;
        }
        fprintf(stdout, "Type in the int value: ");     /*Einlesen des gew�nschten Wertes*/
        fscanf(stdin, "%i", &i);                        /*get char from stdin*/
        element->item.num = i;                          /*Initialisieren des Integers*/
        element->next = NULL;                           /*,-, des next Pointers*/
    }
    else if(choice == 'c' || choice == 'C'){            /*bei Char eingabe*/
        element = (ELEM*)malloc(sizeof(ELEM));
        if(NULL == element){                            /*Fehler�b.*/
            fprintf(stderr, "failure with malloc!\n");
            return NULL;
        }
        fprintf(stdout, "Type in the char value: ");    /*einlesen eines Buchstabens*/
        fscanf(stdin, "%c", &c);
        element->item.sym = c;                          /*Initialisieren des char Pointers*/
        element->next = NULL;                           /*,-, des next Pointers mit NULL*/
    }
    if(header->len == 0){                               /*Wenn elem das erste Element ist*/
        header->next = element;                         /*Initialisieren des next Pointers zum n�chsten element*/
        header->last = element;                         /*,-, des last pointers zu element*/
        header->len++;                                  /*Erh�hen der L�nge um +1 */
    }
    else{                                               /*wenn es nicht das erste Element ist*/
        header->last->next = element;                   /*init pointer to last elem*/
        header->len++;                                  /*erh�hen der L�nge um +1*/
    }
    return element;                                     /*Addresse von Element zur�ck geben*/
}

/*funktion Pup() entfernt das erste element vom Stack*/
ELEM *pop(STACK_H *header){                             /*remove elem from stack*/
    ELEM *element, *hlp;                                /*Adresse vom Element*/
    element = header->last;                             /*Element mit Addresse Initialisieren*/
    int count = 1;                                      /*Z�hler*/
    if(header->len == 0){                               /*wenn der Stack leer ist*/
        fprintf(stderr, "Stack is empty!\n");
        return NULL;
    }
    int len = header->len;                              /*Initilisieren von len mit len von stack*/
    hlp = header->next;
    if(header->len == 1){                               /*wenn ein Element am Stack ist*/
        header->next = NULL;
        header->last = NULL;
        header->len--;
    }
    else{
        while(count == (len-1)){                        /*bis zu dem vorletzten Element*/
            hlp = hlp->next;                            /*init next elem*/
            count++;                                    /*Z�hler erh�hen*/
        }
        header->last = hlp;                             /*vorletzte element ist das neue erste Element*/
        hlp->next = NULL;                               /*Initialisieren des Pinters vom Header zum letzten*/
        header->len--;                                  /*L�nge verringern*/
    }
    return element;                                     /*Den Pointer zu dem element zur�ck geben */
}

/*Funktion Top() welches die Adress des obersten Elements zur�ck gibt*/
ELEM *top(STACK_H *header){
    if(NULL == header){                                 /*Fehler�berpr�fung*/
        fprintf(stderr, "failure with pointer!\n");
        return NULL;
    }
return header->last;                                    /*Pointer des letzten zur�ck geben*/
}
