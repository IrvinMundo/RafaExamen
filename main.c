#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_entradas 500
struct Entrada {
    char palabra[20];     /* la palabra */
    int lineas[10];   /* el número de línea en el que aparece */
    int total;        /* total de apariciones de la palabra en el texto */
};

typedef struct Renglon{
    int renglon;
    struct Palabra* pal;
    struct Renglon* siguiente;
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

void add_Renglon(Renglon ** head, Palabra * val, int renglon) {
    if(*head==NULL){
        (*head)=(Renglon *) malloc(sizeof(Renglon));
        (*head)->pal=val;
        (*head)->renglon=renglon;
        (*head)->siguiente=NULL;
    }else{
        Renglon *current=(*head)->siguiente;
        while(current->siguiente!=NULL){
            current=current->siguiente;
        }
        (*current).siguiente=NULL;
        (*current).renglon=renglon;
        (*current).pal=val;
    }
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
    }
}

void print_Palabra(Palabra * head) {
    Palabra * current = head;

    while (current != NULL) {
        printf("%s en el columna %d en la fila %d\n", current->palabra,current->numerocolumna, current->numerofila);
        current = current->siguiente;
    }
    printf("-----------\n");
}

void print_Renglon(Renglon * head) {
    Renglon * current = head;

    while (current != NULL) {
        Palabra * pal=current->pal;
        printf("Estoy en el renglon %d\n", current->renglon);
        print_Palabra(pal);
        current = current->siguiente;
    }
    printf("\n");
}

typedef struct Entrada Entrada;

int main() {
    Entrada entradas[max_entradas] = {{"",{0},0}}; /* inicializa el arreglo */
    char *linea;
    size_t tamanio;

    Palabra * cabeza=NULL;
    Renglon * head=NULL;
    int j=0;

    while (getline(&linea,&tamanio, stdin) != -1) {
        char palabras[100][21];
        int len = split(linea,palabras);
        int i;
        for (i = 0; i < len; i++) {
            Palabra * pal = (Palabra *) malloc(sizeof(Palabra));
            pal->siguiente = NULL;
            pal->numerocolumna = i;
            pal->numerofila = j;
            pal->palabra = palabras[i];
            add_Lista(&cabeza,pal);
            //printf("palabra %d = %s\n", i, palabras[i]);
        }
        //print_Palabra(cabeza);
        add_Renglon(&head,cabeza,j);
        print_Renglon(head);
        j++;
    }
}