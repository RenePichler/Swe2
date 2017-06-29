#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "binarytree.h"
#include "console.h"
#include <winsock2.h>
#include <pthread.h>
#include <time.h>
#define SENBUFSIZE 2048
#define RCVBUFSIZE 2048
#define PORT 8080


int main(int argc, char **argv){
    if(argc == 2){                       // Ini für Windows
        WORD wVersionRequested;
        WSADATA wsaData;
        wVersionRequested = MAKEWORD (1, 1);
        if(WSAStartup(wVersionRequested, &wsaData) != 0){
            errorMessage("failure with init winsock!");
        }
        else{
            printf("Winsock initialisiert\n");
        }

        char *echo_string;                  //message String
        char buffer[RCVBUFSIZE];            //buffer Sting
        SOCKET sock;                        //Socket
        SOCKADDR_IN server;                 //struct für Server
        unsigned long addr;                 //IPv4 address
        int buff_len, echo_len;             //slänge buff

        sock = socket(AF_INET, SOCK_STREAM, 0);
        if(sock < 1){
            errorMessage("can't create socket!");
            return -1;
        }

        memset(&server, 0, sizeof(server));
        if((addr = inet_addr(argv[1])) != INADDR_NONE){
            memcpy((char*)&server.sin_addr, &addr, sizeof(addr));
        }
        server.sin_family = AF_INET;        //IPv4
        server.sin_port = htons(PORT);      //PORT

        if(connect(sock,(struct sockaddr*)&server,sizeof(server)) < 0){
            errorMessage("can't connect to Server!");
            return -3;
        }

        client_header();                    //Header in chat server

//main Schleife
        while(1){
            fgets(buffer, RCVBUFSIZE, stdin);
            buff_len = strlen(buffer);
            buffer[buff_len-1] = '\0';
            if(strcmp(buffer, "exit") == 0){
                break;
            }
            echo_string = write_morsecode(buffer);
            echo_len = strlen(echo_string);
            echo_string[echo_len] = '\0';
            if(send(sock, echo_string, echo_len, 0) != echo_len){
                errorMessage("Send has a larger number of bytes than expected");
            }
        }


        closesocket(sock);
        return 0;
    }

    else if(argc == 1){                  //server mode

//Init. TCP for Windows
        WORD wVersionRequested;
        WSADATA wsaData;
        wVersionRequested = MAKEWORD (1, 1);
        if(WSAStartup(wVersionRequested, &wsaData) != 0){
            errorMessage("failure with init winsock!");
        }
        else{
            printf("Winsock initialisiert\n");
        }

        SOCKET sock, fd;
        SOCKADDR_IN server, client;
        unsigned long len;
        NODE *root = create_morsecode_tree();
        sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
        if(sock < 1){                    //error control
            errorMessage("can't create socket!");
            return -1;
        }

        memset(&server, 0, sizeof(server));
        server.sin_family = AF_INET;     //IPv4
        server.sin_addr.s_addr = htonl(INADDR_ANY);
        server.sin_port = htons(PORT);   //Port

        if(bind(sock,(struct sockaddr*)&server, sizeof(server)) < 0){
            errorMessage("can't bind socket!");
            return -2;
        }
//Warte auf anfragen
        if(listen(sock, 5) == -1){
            errorMessage("failure with listen!");
            return -3;
        }
        server_header();
//Server Schleife
        for(;;){
            len = sizeof(client);
            fd = accept(sock, (struct sockaddr*)&client, &len);
            if(fd < 0){
                errorMessage("fault with accept!");
                return -4;
            }
            printf("Processing request from client with address: %s\n", inet_ntoa(client.sin_addr));
            echo(fd, root);
        }

        closesocket(sock);
        return 0;
    }
    return 1;
}
