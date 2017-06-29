#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

typedef struct image{                    //Bild Strukt
    int pcode;
    char buffer[80];
    int width;
    int height;
    int max;
} IMAGE;

void readimage(char *pfad, IMAGE*);      //Funktion, lesen vom PNG file und speichern in der Struktur
void safeimage(IMAGE*);                  //Struct als PNG Speichern
#endif
