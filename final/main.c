#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"
#include "ArrayList.h"
#include "datos.h"


int main()
{

    //menuModifica();
    char seguir = 's';
    int opcion=0;
    int opcion1=0;
    eNumero* num;
    ArrayList* alta = al_newArrayList();
    ArrayList* clonada = al_newArrayList();
    ArrayList* depurado = al_newArrayList();

    while(seguir=='s')
    {

        printf("1- Altas\n");
        printf("2- completar\n");
        printf("3- listar\n");
        printf("4- generar\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            cargarPersonas(alta,"datos.csv");

            mostrarTodos(alta);
            system("pause");
            break;
        case 2:
            vali1(alta);
            mostrarTodos(alta);
            system("pause");
            break;
        case 3:
            printf("1)Ordenar con repeticion y de menor a mayor\n");
            printf("2)Ordenar sin repeticion y de mayor a menor\n");
            printf("INDIQUE OPCION: ");
            scanf("%d",&opcion1);
            switch(opcion1)
            {
            case 1:
                clonada= alta->clone(alta);
                clonada->sort(clonada,ordenar,1);
                mostrarTodos(clonada);
                system("pause");
                break;
            case 2:
                depurado= alta->clone(alta);
                depurado->sort(depurado,ordenar,0);
                depurar(depurado);
                mostrarTodos(depurado);
                system("pause");
                break;
            }

        case 4:
            system("pause");
            break;
        case 5:
            seguir = 'n';
            break;
        }
    }


    return 0;
}
