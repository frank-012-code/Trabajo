#include <stdio.h>
#include <string.h>

void ingresoProductos(char productos[][30], int pantallas[], int baterias[], int chips[], int tiempo[], int contador);
void eliminarProducto(char productos[][30], int pantallas[], int baterias[], int chips[], int tiempo[], int *cont, int indice);
int validarPositivos();
void leerProducto(char *producto, int n);
void imprimirProductos(char productos[][30], int pantallas[], int baterias[], int chips[], int tiempo[], int cont);
int validarEnteros(int min, int max);
int validarIndice(int contador);
void calculoRecursos(int componente[], int indice, int cantidad, int stock, char texto[]);
void opcionIngreso(char productos[][30], int pantallas[], int baterias[], int chips[], int tiempo[], int *cont);
void opcionStock(int *stock_pantallas, int *stock_baterias, int *stock_chips, int cont);
void opcionEdicion(char productos[][30], int pantallas[], int baterias[], int chips[], int tiempo[], int cont);
void opcionEliminar(char productos[][30], int pantallas[], int baterias[], int chips[], int tiempo[], int *cont );
void opcionCalculo(char productos[][30], int pantallas[], int baterias[], int chips[], int tiempo[], int cont, int stock_pantallas, int stock_baterias, int stock_chips);
void calculoTiempo(int tiempo_por_producto, int cantidad, int tiempo_disponible);