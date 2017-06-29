#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

//Stack erstellen
HEAD *create_stack(void){
    HEAD *stack;
    stack = (HEAD*)malloc(sizeof(HEAD));
    if(NULL == stack){
        return NULL;
    }
    stack->len = 0;
    stack->first = NULL;
    stack->last = NULL;
    return stack;
}

//Push funktion
ELEM *push(HEAD *head, char t){
    if(NULL == head){
        return NULL;
    }
    ELEM *elem;
    elem = (ELEM*)malloc(sizeof(ELEM));
    if(NULL == elem){
        return NULL;
    }
    if(head->len == 0){
        elem->elem = t;
        elem->next = NULL;
        elem->prev = NULL;
        head->first = elem;
        head->last = elem;
        head->len++;
    }
    else{
        elem->elem = t;
        elem->prev = NULL;
        elem->next = head->first;
        head->first->prev = elem;
        head->first = elem;
        head->len++;
    }
    return elem;
}

//Pop funktion
ELEM *pop(HEAD *head){
    ELEM *elem;
    if(NULL == head){
        return NULL;
    }
    if(head->len == 0){
        fprintf(stdout, "Stack ist leer\n");
        return NULL;
    }
    if(head->len == 1){
        elem = head->first;
        head->first = NULL;
        head->last = NULL;
        head->len--;
        free(elem);
    }
    else if(head->len > 1){
        elem = head->first;
        head->first->next->prev = NULL;
        head->first = head->first->next;
        head->len--;
        free(elem);
    }
    return head->first;
}

//Top Funktion
ELEM *top(HEAD *head){
    if(NULL == head){
        return NULL;
    }
    if(head->len == 0){
        fprintf(stdout, "stack is empty");
    }
    ELEM *elem = head->first;
    return elem;
}

//Stack leeren
int emptystack(HEAD *head){
    ELEM *elem = head->first;
    if(head == NULL){
        return -1;
    }
    if(head->len == 0){
        fprintf(stderr, "Stack ist leer\n");
        return -2;
    }
    while(elem != NULL){
        fprintf(stdout, "%c ", elem->elem);
        elem = elem->next;
    }
    elem = head->last;
    while(head->len > 1){
        head->last = elem->prev;
        head->last->next = NULL;
        head->len--;
        free(elem);
        elem = head->last;
    }
    while(head->len == 1){
        elem = head->first;
        free(elem);
        head->len = 0;
        head->first = NULL;
        head->last = NULL;
    }
    return 0;
}

//Stack füllen
int fill_stack(HEAD *head, const char *s){
    if(NULL == head)
        return -1;
    if(NULL == s)
        return -2;
    while(*s != '\0'){
        push(head, *s);
        s++;
    }
    return 0;
}
