#include <stdio.h>
#include <stdlib.h>
#include "console.h"
#include <winsock2.h>
#include <time.h>
#include "binarytree.h"

#define RCVBUFSIZE 2048

//Fehlerfunktion
void errorMessage(const char *message){
    time_t c_time;
    time(&c_time);
    fprintf(stdout ,"%s : %d | time: %s\n", message, WSAGetLastError(), ctime(&c_time));
}

//Hilfsfunktin
void showhelp(void){
    fprintf(stdout, "               [argv]\n");
    fprintf(stdout, "Start Server: .......\n");
    fprintf(stdout, "Start Client: IPv4 address\n");
}

//Header für Client Funktion
void client_header(void){
    time_t c_time;
    fprintf(stdout, "Client ready! Connection successful created\n");
    fprintf(stdout, "-------------------------------------------\n");
    time(&c_time);
    fprintf(stdout, "Time: %s\n", ctime(&c_time));
    fprintf(stdout, "Welcome\n");
}

//Header für Server
void server_header(void){
    time_t c_time;
    fprintf(stdout, "Server ready! Waiting for requests ........\n");
    fprintf(stdout, "-------------------------------------------\n");
    time(&c_time);
    fprintf(stdout, "Time: %s\n", ctime(&c_time));
    fprintf(stdout, "Welcome\n");
}

//Echo socket,client
void echo(SOCKET *client, NODE *root){
    char echo_buffer[RCVBUFSIZE];
    int recv_size;
    time_t c_time;
    recv_size = recv(client, echo_buffer, RCVBUFSIZE, 0);
    if(recv_size < 0){
        errorMessage("failure with recv()!");
    }
    echo_buffer[recv_size] = '\0';
    read_morsecode(echo_buffer, root);
    time(&c_time);
    fprintf(stdout, " | %s\n", ctime(&c_time));
}
