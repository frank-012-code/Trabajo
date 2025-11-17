#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main(int argc, char const *argv[])
{
    int opc, opc2, cont = 0;
    char productos[5][30];
    int pantallas[5], baterias[5], chips[5], tiempo[5];
    int stock_pantallas = 0, stock_baterias = 0, stock_chips = 0;
    int total;

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

            opcionIngreso(productos, pantallas, baterias, chips, tiempo, &cont);

            break;

        case 2:

            opcionStock(&stock_pantallas, &stock_baterias, &stock_chips, cont);

            break;
        
        case 3:

            opcionEdicion(productos, pantallas, baterias, chips, tiempo, cont);

            break;
        case 4:

            opcionEliminar(productos, pantallas, baterias, chips, tiempo, &cont);

            break;

        case 5:
            if (cont == 0)
            {
                printf("No hay productos ingresados.\n");
            }
            else
            {
                imprimirProductos(productos, pantallas, baterias, chips, tiempo, cont);
            }

            break;
        
        case 6:

            opcionCalculo(productos, pantallas, baterias, chips, tiempo, cont, stock_pantallas, stock_baterias, stock_chips);

            break;

        default:
            break;
        }

            printf("Desea cerrar el programa? 0. Si / 1. No: ");
            opc2 = validarEnteros(0, 1);
        
    } while (opc2 != 0);
    
    return 0;
}
