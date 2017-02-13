#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_entradas 500
typedef struct Entrada {
    char palabra[20];     /* la palabra */
    int lineas[10];   /* el número de línea en el que aparece */
    int total;        /* total de apariciones de la palabra en el texto */
};

typedef struct Renglon{
    char* name;
    int renglon;
    struct Palabra* head;
} Renglon;

typedef struct Palabra{
    char* palabra;
    int numerofila;
    int numerocolumna;
    struct Palabra *siguiente;
}Palabra;

int split(char *str, char palabras[][21]) {
    int i = -1;
    char *tmp;
    tmp = strtok(str," \t\n.¿?:");
    while(tmp) {
        strcpy(palabras[++i],tmp);
        tmp = strtok(NULL," \t\n.¿?:");
    }
    return ++i;
}

void add_Lista(Palabra ** head,  Palabra * val) {
    if(*head==NULL){
        (*head)=val;
    }else{

        Palabra *current=*head;
        while(current->siguiente!=NULL){
            current=current->siguiente;
        }
        current->siguiente=val;
        val->siguiente=NULL;
    }
}

void printWords(char palabras[][21]){
    for(int i=0;i<10;i++){

    }
}

typedef struct Entrada Entrada;

int main() {
    Entrada entradas[max_entradas] = {{"",{0},0}}; /* inicializa el arreglo */
    char *linea;
    size_t tamanio;

    Palabra * cabeza=NULL;
    Palabra * pal=NULL;

    int j=0;

    while (getline(&linea,&tamanio, stdin) != -1) {
        char palabras[100][21];
        int len = split(linea,palabras);
        int i;
        for (i = 0; i < len; i++) {
            pal = (Palabra *) malloc(sizeof(Palabra));
            pal->siguiente = NULL;
            pal->numerocolumna = i;
            pal->numerofila = j;
            add_Lista(&cabeza,pal);
            printf("palabra %d = %s\n", i, palabras[i]);
        }
        j++;
    }



}