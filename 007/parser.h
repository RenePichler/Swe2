#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <stdbool.h>

char *s;                               //globaler Pointer
bool expression(FILE*);                //F. f�r expressions
bool term(FILE*);                      //F. f�r term
bool factor(FILE*);                    //F. f�r faktor
bool variable(FILE*);                  //F. f�r Vaariablen
bool constant(FILE*);                  //F. f�r Konstanten
bool digit(FILE*);                     //F. f�r Digit

#endif
