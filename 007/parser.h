#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <stdbool.h>

char *s;                               //globaler Pointer
bool expression(FILE*);                //F. für expressions
bool term(FILE*);                      //F. für term
bool factor(FILE*);                    //F. für faktor
bool variable(FILE*);                  //F. für Vaariablen
bool constant(FILE*);                  //F. für Konstanten
bool digit(FILE*);                     //F. für Digit

#endif
