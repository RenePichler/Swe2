#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

//PNG File einlesen und save in pic struktur
void readimage(char *pfad, IMAGE *image){
    FILE *in;
    in = fopen(pfad, "r");
    if(NULL == in){
        fprintf(stderr, "Fehler mit File\n");
        exit(-1);
    }
//Parsen der werte aus dem File und in globales Strukt einlesen
    fscanf(in, "P%d\n", &image->pcode);
    printf("Der PCODE lautet %d\n", image->pcode);
    fscanf(in, "#%s\n", image->buffer);
    printf("Dateiname: %s\n", image->buffer);
    fscanf(in, "%d\t%d\n", &image->width, &image->height);
    printf("Anzahl Zeilen: %d\t Anzahl Spalten: %d\n", image->height, image->width);
    fscanf(in, "%d\n", &image->max);
    printf("Hoechster Wert: %d\n", image->max);
//Werte von PNG bild in 2D Array

    int i, j;
    //gef‰hrlich weil implizites malloc
    int img[image->height][image->width];       //Das Array durchwandern
    for(i = 0; i < image->height; ++i){
        for(j = 0; j < image->width; ++j){
            int tmp;
            fscanf(in, "%d\t", &tmp);
            img[i][j] = tmp;
            printf("%d\t", img[i][j]);
        }
        fscanf(in, "\n");
        printf("\n");
    }
    fclose(in);

//Struktur als PGM file speichern

void safeimage(IMAGE *image){
    int i, j;

    char buffer[80];
    char dname[80];
    fprintf(stdout, "Bitte geben Sie den Dateinamen zum Speichern an: ");
    scanf("%75s", buffer);
    strcpy(dname, buffer);
    strcat(dname, ".pgm");
    fprintf(stdout, "Dateiname: %s\n", dname);

    FILE *out = fopen(dname, "w");
    if(NULL == out){
        fprintf(stderr, "Konnte Datei %s nicht oeffnen!\n", "bw.pgm");
        exit(-2);
    }
    int img[image->height][image->width];
//Header in File schreiben

    fputs("P2\n#", out);
    fprintf(out, "%s\n", image->buffer);
    fprintf(out, "%d\t%d\n", sizeof(img[0])/sizeof(int), sizeof(img)/sizeof(img[0]));
    fprintf(out, "%d\n", 1);
//Bild in neues Bild und zu sw konvertieren
        for(j = 0; j < image->width; ++j){
            if(img[i][j] > (image->max/2))
                fprintf(out, "1\t");            //Schwarz
            else
                fprintf(out, "0\t");            //Weiﬂ
        }
        fprintf(out, "\n");
    }
    fclose(out);                                //Schlieﬂen
}
