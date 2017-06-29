#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "parser.h"


//Ausdrücke fl
bool expression(FILE *fp){
    if(term(fp) == true){
        if(*s == '+' || *s == '-'){             //Überpr. der Ausdrücke
            s++;
            if(expression(fp) == true){
                return true;                    //Suchen auf vorhanden oder nicht
            }
            else{
                return false;
            }
        }
        return true;
    }
    return false;
}
//Terme
bool term(FILE *fp){
    if(factor(fp) == true){
        if(*s == '*' || *s == '/'){
            s++;
            if(term(fp) == true){
                return true;
            }
            else{
                return false;
            }
        }
        return true;
    }
    return false;
}

//Funktion für Faktoren
bool factor(FILE *fp){
    if(constant(fp) == true){                   //Ob Konstante
        return true;
    }
    if(variable(fp) == true){                   //Ob Variable
        return true;
    }
    if(*s == '('){                              //.. Klammer
        s++;
        if(expression(fp) == true){
            if(*s == ')'){
                s++;
                if(*s == '\0'){
                    fprintf(fp, "Ende des Strings erreicht");
                    fprintf(stdout, "Ende des Strings errecht");
                    return true;
                }
                return true;
            }
        }
    }
    return false;
}

// Funktion für Variablen
bool variable(FILE *fp){
    if(*s >= 'a' && *s <= 'f'){                 //Ab zwischen a und f
        fprintf(fp, "variable found! [%c]\n", *s);
        fprintf(stdout, "variable found! [%c]\n", *s);
        s++;
        if(*s == '\0'){
            fprintf(fp, "Ende des Strings erreicht\n");
            fprintf(stdout, "Ende des Strings erreicht\n");
            return true;
        }
        return true;
    }
    fprintf(fp, "Keine Variable gefunden [%c]\n", *s);
    return false;
}

//Funktion f. Konstanten
bool constant(FILE *fp){
    if(digit(fp) == true){
        while(digit(fp) == true){
            fprintf(fp, "constant found! [%c]\n", *s);
            fprintf(stdout, "constant found! [%c]\n", *s);
            s++;
        }
        return true;
    }
    fprintf(fp, "no constant found! [%c]\n", *s);
    return false;
}

//Funktion f. Digit
bool digit(FILE *fp){
    if(*s >= '0' && *s <= '9'){
        fprintf(fp,"digit gefunden [%c]\n", *s);
        fprintf(stdout,"digit gefunden [%c]\n", *s);
        s++;
        if(*s == '\0'){
            fprintf(fp, "Ende des Strings erreicht\n");
            fprintf(stdout, "Ende des Strings erreicht\n");
            return true;
        }
        return true;
    }
    fprintf(fp, "kein digit gefunden [%c]\n", *s);
    return false;
}
