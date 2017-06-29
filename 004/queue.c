#include <stdio.h>
#include <stdlib.h>
#include "head.h"

/*Funktion um die Dequeue zu erzeugen*/
HEAD *create_de_queue(void){
    HEAD *de_queue;                                     /*Pointer f�r dequeue*/
    de_queue = (HEAD*)malloc(sizeof(HEAD));
    if(NULL == de_queue){                               /*Bestimmungen f�r Pointer*/
        fprintf(stderr, "failure with malloc!\n");
        return NULL;
    }
    de_queue->first = NULL;                             /*Initialisieren des Pointers zu dem ersten Element*/
    de_queue->last = NULL;                              /*,-, zu dem letzten Element*/
    de_queue->len = 0;                                  /*,-, der l�nge der Liste*/
    return de_queue;                                    /*Pointer zum Header der Liste zur�ck geben*/
}

/*Funktion um enque ..*/
ELEM *enqueue(HEAD *header){                            /*Element vorne hinzuf�gen*/
    int i = 0;
    char c, choice;                                     /*Char und buff f�r Auswahl*/
    ELEM *element;                                      /*Pointer auf Element*/
    do{
        printf("What do you want to do? insert new int(i) or new char(c), your choice: ");
        scanf("%c", &choice);
    } while(getchar() != '\n');                         /*bis \n*/
    if(choice == 'i' || choice == 'I'){                 /*wenn int*/
        element = (ELEM*)malloc(sizeof(ELEM));
        if(NULL == element){                            /*Fehler�berpr�fung*/
            fprintf(stderr, "failure with malloc!\n");
            return NULL;
        }
        fprintf(stdout, "Type in the int value: ");
        fscanf(stdin, "%i", &i);                        /*Int wert einlesen*/
        element->item.num = i;                          /*Initialisiern des integers*/
        element->next = NULL;                           /*,-, des next pointers*/
    }
    else if(choice == 'c' || choice == 'C'){            /*bei char*/
        element = (ELEM*)malloc(sizeof(ELEM));
        if(NULL == element){                            /*Fehler�berpf�fung*/
            fprintf(stderr, "failure with malloc!\n");
            return NULL;
        }
        fprintf(stdout, "Type in the char value: ");
        fscanf(stdin, "%c", &c);
        element->item.sym = c;                          /*Initialisieren des char*/
        element->next = NULL;                           /*,-, des next pointers*/
    }
    if(header->len == 0){                               /*wenn das erste element*/
        header->first = element;                        /*initialisieren des Pointers auf das erste Element*/
        header->last = element;                         /*Initialisieren des Pointers auf das letzte Element*/
        header->len++;                                  /*increment length*/
    }
    else{
        element->next = header->first;                  /*element next pointer*/
        header->first = element;                        /*init first elem*/ //???
        header->len++;                                  /*L�nge erh�hen*/
    }
    return element;                                     /*Addresse des Elementes zur�ck geben*/
}

/*funktion dequeue*/
ELEM *dequeue(HEAD *header){                            /*Element von de. entfernen*/
    ELEM *element;                                      /*Pointer auf das Element*/
    int count = 0;                                      /*Z�hler*/
    if(header->len == 0){                               /*wenn die queue leer ist*/
        fprintf(stderr, "queue is empty!\n");           /*Ausgabe*/
        return NULL;
    }
    int len = header->len;                              /*Initialisieren von len*/
    element = header->first;                            /*,-, element Pointer*/
    while(count == (len-1)){                            /*bis zum vorletzten*/
        element = header->first->next;                  /*Initialisieren Pointer*/
        count++;                                        /*Z�hler +1*/
    }
    if(header->len == 1){
        header->last = NULL;                            /*Initialisieren des neuen letzten Elements*/
        header->first = NULL;                           /*,-, ersten Elements*/
        header->len--;                                  /*lenge veringern*/
    }
    else{                                               /*if len > 1*/
        header->last = element;                         /*init pointer*/
        header->last->next = NULL;                      /*init next pointer*/
        header->len--;                                  /*decrement len*/
    }
    return element;                                     /*Pointer auf das Element zur�ck geben*/
}

/**Front Funktion*/
ELEM *front(HEAD *header){                              /*Addresse des ersten Elements zur�ck geben*/
    if(NULL == header){                                 /*Fehler�berpr�fung*/
        fprintf(stderr, "failure with pointer!\n");
        return NULL;
    }
    return header->last;                                /*Pointer von elem zur�ck geben*/
}

/*Back Funktion*/
ELEM *back(HEAD *header){                               /*Addresse des letzten Elements zur�ck geben*/
    if(NULL == header){                                 /*Fehler�berpr�fung*/
        fprintf(stderr, "failure with pointer!\n");
        return NULL;
    }
    return header->first;                               /*Pointer auf das back elem zur�ck geben*/
}
