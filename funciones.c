#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresoProductos(char productos[][30], int pantallas[], int baterias[], int chips[], int tiempo[], int contador)
{
    printf("Ingrese el producto[%d]: ", contador);
    leerProducto(productos[contador], 30);

    printf("Cantidad de pantallas para produccion: ");
    pantallas[contador] = validarPositivos();

    printf("Cantidad de baterias para produccion: ");
    baterias[contador] = validarPositivos();

    printf("Cantidad de chips para produccion: ");
    chips[contador] = validarPositivos();

    printf("Tiempo de produccion(minutos): ");
    tiempo[contador] = validarPositivos();
}

int validarPositivos()
{
    int valor;
    do
    {
        scanf("%d", &valor);
        if (valor < 0)
        {
            printf("Dato no valido.\n");
        }
        
    } while (valor < 0);

    return valor;
}

void leerProducto(char *producto, int n)
{
    fflush(stdin);
    fgets(producto, n, stdin);
    int len = strlen(producto) - 1;
    producto[len] = '\0';

}

void imprimirProductos(char productos[][30], int pantallas[], int baterias[], int chips[], int tiempo[], int cont)
{
    printf("# \t Producto \t Pantallas \t Baterias \t Chips \t Tiempo\n");
                for (int i = 0; i < cont; i++)
                {
                    printf("%d \t %s \t %d \t\t %d \t %d \t\t %d\n", i, productos[i], pantallas[i], baterias[i], chips[i], tiempo[i]);
                }
}

int validarEnteros(int min, int max)
{
    int valor;
    do
    {
        scanf("%d", &valor);
        if (valor < min || valor > max)
        {
            printf("Dato no valido.\n");
        }
        
    } while (valor < min || valor > max);
    

    return valor;
}

int validarIndice(int contador)
{
    int valor;
    do
    {
        printf("Indice producto: ");
        scanf("%d", &valor);
        if (valor < 0 || valor >= contador)
        {
            printf("Dato no valido.\n");
        }
    } while (valor < 0 || valor >= contador);

    return valor;
}

void calculoRecursos(int componente[], int indice, int cantidad, int stock, char texto[])
{
    int total;

    total = componente[indice] * cantidad;

    if (total > stock)
    {
        printf("Faltan %d %s.\n", total - stock, texto);
    }
    else
    {
        printf("Es posible producir.\n");
    }
    
}