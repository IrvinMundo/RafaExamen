#include <stdio.h>
#include <stdlib.h>

#define max_entradas 500
struct Entrada {
    char palabra[20];     /* la palabra */
    int lineas[10];   /* el número de línea en el que aparece */
    int total;        /* total de apariciones de la palabra en el texto */
};

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
typedef struct Entrada Entrada;
int main() {
    Entrada entradas[max_entradas] = {{"",{0},0}}; /* inicializa el arreglo */
    char *linea;
    size_t tamanio;
    while (getline(&linea,&tamanio, stdin) != -1) {
        char palabras[100][21];
        int len = split(linea,palabras);
        int i;
        for (i = 0; i < len; i++)
            printf("palabra %d = %s\n",i,palabras[i]);
    }
}

int main() {

    char* linea[]=

    scanf("%s",)

    return 0;
}