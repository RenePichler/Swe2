#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

typedef union char_or_int{             /*union ist entweder int oder char */
    int num;
    char sym;
} DATA;                                 /*alias DATA*/

typedef struct elem{                    /*listelement*/
    struct elem *next;                  /*pointer zum n�chsten Element*/
    DATA item;                          /*union in listelement*/
} ELEM;

typedef struct head{                    /*header*/
    ELEM *first;                        /*Pointer auf das erste Element*/
    ELEM *last;                         /*Pointer auf das Letzte Element*/
    int len;                            /*l�nge*/
} HEAD;

typedef struct stack_head{              /*Header von dem Stack*/
    ELEM *next;                         /*Pointer auf das N�chste Element*/
    ELEM *last;                         /*Pointer auf das letzte Element*/
    int len;                            /*L�nge des Stack*/
} STACK_H;

HEAD *create_de_queue(void);            /*Neue deque erstellen*/
STACK_H *create_stack(void);            /*Neuen Stack erstellen*/
ELEM *push(STACK_H*);                   /*Neues element auf den Stack ablegen*/
ELEM *enqueue(HEAD*);                   /*Neues Element vorne Einsetzen*/
ELEM *dequeue(HEAD*);                   /*Letztes element aus der Liste entfernen*/
ELEM *pop(STACK_H*);                    /*Erstes Element vom Stack entfernen und Addresse zur�ck geben*/
ELEM *front(HEAD*);                     /*Addresse des ersten queue Elementes zur�ck geben*/
ELEM *top(STACK_H*);                    /*Addresees des ersten Stack Elements zur�ck geben*/
ELEM *back(HEAD*);                      /*Adresse des letzten Elements zur�ck geben*/

#endif // HEAD_H_INCLUDED
