#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct elem{                 //Stack Elemente
    char elem;
    struct elem *prev;
    struct elem *next;
} ELEM;

typedef struct head{                  //Stack für Header
    int len;
    ELEM *first;
    ELEM *last;
} HEAD;

HEAD *create_stack(void);        //Stack Funktionen
ELEM *push(HEAD*, char);
ELEM *pop(HEAD*);
ELEM *top(HEAD*);
int emptystack(HEAD*);
ELEM *to_outputstack(char*);
int fill_stack(HEAD*, const char*);

#endif
