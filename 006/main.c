#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

#define MAX 30


int main(void){
    printf("PNG Test Programm \n");
    char fname[MAX];                            //Buff für Filename
    fprintf(stdout, "Geben Sie bitte den Dateinamen an: ");
    fgets(fname, MAX-1, stdin);                 //get file von stdint
    fname[strlen(fname) - 1] = '\0';            //Ers. neue Zeile
    IMAGE image;                                //Struct für Image
    readimage(fname, &image);                   //Bild einlesen
    safeimage(&image);                          //Bild in neues File
    return 0;
}
