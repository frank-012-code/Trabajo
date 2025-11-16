#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main(int argc, char const *argv[])
{
    int opc, opc2, opc3, cont = 0, indice;
    char productos[5][30];
    int pantallas[5], baterias[5], chips[5], tiempo[5];
    int stock_pantallas, stock_baterias, stock_chips, tiempo_total;
    int total, produccion_pantallas, produccion_baterias, produccion_chips;

    do
    {

        printf("\n*** Sistema ***\n");
        printf("1. Ingresar productos\n");
        printf("2. Cantidad en stock.\n");
        printf("3. Editar producto.\n");
        printf("4. Eliminar producto.\n");
        printf("5. Revisar productos.\n");
        printf("6. Calcular produccion.\n");
        printf(">>> ");

        opc = validarEnteros(1, 6);

        switch (opc)
        {
        case 1:
            if (cont == 5)
            {
                printf("Ya no se pueden ingresar mas productos.\n");
            }
            else
            {
                ingresoProductos(productos, pantallas, baterias, chips, tiempo, cont);

                cont ++;
            }

            break;

        case 2:
            if (cont == 0)
            {
                printf("No se han ingresado productos.\n");
            }
            else
            { 
                printf("Cantidad en stock de pantallas: ");
                stock_pantallas = validarPositivos();
                
                printf("Cantidad en stock de baterias: ");
                stock_baterias = validarPositivos();
                
                printf("Cantidad en stock de chips: ");
                stock_chips = validarPositivos();

            }
            

            break;
        
        case 3:
            if (cont == 0)
            {
                printf("No se han ingresado productos.\n");
            }
            else
            {   
                imprimirProductos(productos, pantallas, baterias, chips, tiempo, cont);
                indice = validarIndice(cont);

                printf("Nuevo producto:\n");
                ingresoProductos(productos, pantallas, baterias, chips, tiempo, indice);
            }
            
            break;
        case 4:
            if (cont == 0)
            {
                printf("No hay productos a eliminar.\n");
            }
            else
            {

                imprimirProductos(productos, pantallas, baterias, chips, tiempo, cont);

                indice = validarIndice(cont);

                for (int i = indice; i < cont - 1; i++)
                {
                    strcpy(productos[i], productos[i +1]);
                    pantallas[i] = pantallas[i + 1];
                    baterias[i] = baterias[i + 1];
                    chips[i] = chips[i + 1];
                    tiempo[i] = tiempo[i + 1];
                }
                cont --;
            }

            break;

        case 5:
            imprimirProductos(productos, pantallas, baterias, chips, tiempo, cont);

            break;
        
        case 6:
            if (cont == 0)
            {
                printf("No se han ingresado productos.\n");
            }
            else
            {
                    imprimirProductos(productos, pantallas, baterias, chips, tiempo, cont);

                    indice = validarIndice(cont);

                    printf("Cuantos desea producir?: ");
                    scanf("%d", &total);

                    printf("En que tiempo (minutos): ");
                    scanf("%d", &tiempo_total);

                    printf("\n*Pantallas: ");
                    calculoRecursos(pantallas, indice, total, stock_pantallas, "pantalla/s");

                    printf("*Baterias: ");
                    calculoRecursos(baterias, indice, total, stock_baterias, "bateria/s");

                    printf("*Chips: ");
                    calculoRecursos(chips, indice, total, tiempo_total, "chips");

                    printf("*Tiempo: ");
                    calculoRecursos(tiempo, indice, total, tiempo_total, "minutos");
                
            }

            break;

        default:
            break;
        }

            printf("Desea cerrar el programa? 0. Si / 1. No: ");
            opc2 = validarEnteros(0, 1);
        
    } while (opc2 == 0);
    
    return 0;
}
