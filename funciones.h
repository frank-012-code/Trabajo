#include <stdio.h>
#include <string.h>
void ingresoProductos(char productos[][30], int pantallas[], int baterias[], int chips[], int tiempo[], int contador);
int validarPositivos();
void leerProducto(char *producto, int n);
void imprimirProductos(char productos[][30], int pantallas[], int baterias[], int chips[], int tiempo[], int cont);
int validarEnteros(int min, int max);
int validarIndice(int contador);
void calculoRecursos(int componente[], int indice, int cantidad, int stock, char texto[]);