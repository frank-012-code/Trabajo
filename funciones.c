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

void eliminarProducto(char productos[][30], int pantallas[], int baterias[], int chips[], int tiempo[], int *cont, int indice)
{
    for (int i = indice; i < *cont - 1; i++)
    {
        strcpy(productos[i], productos[i +1]);
        pantallas[i] = pantallas[i + 1];
        baterias[i] = baterias[i + 1];
        chips[i] = chips[i + 1];
        tiempo[i] = tiempo[i + 1];
    }
    (*cont) --;
    printf("Producto eliminado.\n");
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
    int len = strlen(producto);
    if (len > 0 && producto[len - 1] == '\n')
    {
        producto[len - 1] = '\0';
    }

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

void opcionIngreso(char productos[][30], int pantallas[], int baterias[], int chips[], int tiempo[], int *cont)
{
    if (*cont == 5)
    {
        printf("Ya no se pueden ingresar mas productos.\n");
        }
    else
    {
        ingresoProductos(productos, pantallas, baterias, chips, tiempo, *cont);

    (*cont) ++;
    }
}

void opcionStock(int *stock_pantallas, int *stock_baterias, int *stock_chips, int cont)
{
    if (cont == 0)
    {
        printf("No se han ingresado productos.\n");
    }
    else
    { 
        printf("Cantidad en stock de pantallas: ");
        *stock_pantallas = validarPositivos();
    
        printf("Cantidad en stock de baterias: ");
        *stock_baterias = validarPositivos();
                
        printf("Cantidad en stock de chips: ");
        *stock_chips = validarPositivos();
            }
}

void opcionEdicion(char productos[][30], int pantallas[], int baterias[], int chips[], int tiempo[], int cont)
{
    if (cont == 0)
    {
        printf("No se han ingresado productos.\n");
        return;
    }
    else
    {   
        imprimirProductos(productos, pantallas, baterias, chips, tiempo, cont);
        int indice = validarIndice(cont);

        printf("Nuevo producto:\n");
        ingresoProductos(productos, pantallas, baterias, chips, tiempo, indice);
    }
}

void opcionEliminar(char productos[][30], int pantallas[], int baterias[], int chips[], int tiempo[], int *cont )
{
    if (*cont == 0)
    {
        printf("No hay productos a eliminar.\n");
        return;
    }
    else
    {

        imprimirProductos(productos, pantallas, baterias, chips, tiempo, *cont);

        int indice = validarIndice(*cont);

        eliminarProducto(productos, pantallas, baterias, chips, tiempo, cont, indice);

    }
}

void opcionCalculo(char productos[][30], int pantallas[], int baterias[], int chips[], int tiempo[], int cont, int stock_pantallas, int stock_baterias, int stock_chips)
{
    if (cont == 0 || stock_pantallas == 0 || stock_baterias == 0 || stock_chips == 0)
    {
        printf("No se han ingresado productos o no se ingresaron los stocks.\n");
        return;
    }
    else
    {
        int total;
        int tiempo_total;
        imprimirProductos(productos, pantallas, baterias, chips, tiempo, cont);

        int indice = validarIndice(cont);

        printf("Cuantos desea producir?: ");
        scanf("%d", &total);

        printf("En que tiempo (minutos): ");
        scanf("%d", &tiempo_total);

        printf("\n*Pantallas: ");
        calculoRecursos(pantallas, indice, total, stock_pantallas, "pantalla/s");

        printf("*Baterias: ");
        calculoRecursos(baterias, indice, total, stock_baterias, "bateria/s");

        printf("*Chips: ");
        calculoRecursos(chips, indice, total, stock_chips, "chips");

        printf("*Tiempo: ");
        calculoTiempo(tiempo[indice], total, tiempo_total);

    }
}

void calculoTiempo(int tiempo_por_producto, int cantidad, int tiempo_disponible)
{
    int total = tiempo_por_producto * cantidad;
    if(total > tiempo_disponible)
    {
        printf("No se puede producir. Faltan %d minutos.\n", total - tiempo_disponible);
    }
    else
    {    
        printf("Se puede producir.\n");
    }
}