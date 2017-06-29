#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED
#include <winsock2.h>
#include "binarytree.h"

void errorMessage(const char*);         //Fehler benachrichtigung
void showhelp(void);                    //HIlfsmenü
void client_header(void);               //Client Header
void server_header(void);               //Server Header
void echo(SOCKET*, NODE*);              //Echo Funktion

#endif
