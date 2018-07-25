#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"
#include "ArrayList.h"
#include "datos.h"



//PARSER !

/** \brief Carga en memoria lo obtenido delarchivo
 *
 * \param
 * \param
 * \return retorna 1 si no ocurrio ningun error y -1 si algo falló
 *
 */


/*
int parser_parseEmpleados(char* lista, ArrayList* listaEmpleados)
{

    FILE *fp;
    Empleado* unEmpleado;


    int id;
    char idAux[20];
    char horasAux[20];
    char nombre[128];
    int horasTrabajadas;

    int cant;

    int retorno=-1;
    fp = fopen(lista,"r");
    if(fp!=NULL)
    {
        while(!feof(fp))
        {
            unEmpleado=(Empleado*)malloc(sizeof(Empleado));
            if(unEmpleado!=NULL)
            {
                if(feof(fp))
                {
                    break;
                }
                cant=fscanf(fp,"%[^,],%[^,],%[^\n]\n", idAux,nombre,horasAux);
                if(cant==3)
                {
                    unEmpleado->id=atoi(idAux);
                    unEmpleado->horasTrabajadas=atoi(horasAux);
                    strcpy(unEmpleado->nombre,nombre);

                    listaEmpleados->add(listaEmpleados,unEmpleado);
                    retorno=1;
                }
                else
                    printf("error al leer con fscanf\n");
            }
        }

    }
    else
        printf("no se pudo leer");

    fclose(fp);
    return retorno;
}

*/







/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

//GENERAR ARCHIVO !


/*int generarArchivoSueldos(char* fileName,ArrayList* listaEmpleados)
{
    int i;
    Empleado *Emp;
    FILE *b;
    b=fopen("fileName2", "w");

    for(i=1; i<listaEmpleados->len(listaEmpleados); i++)
    {
        Emp=listaEmpleados->get(listaEmpleados,i);

        fprintf(b,"%d,%s,%d,%d\n",Emp->id,Emp->nombre,Emp->horasTrabajadas,Emp->sueldo);
    }
    fclose(b);

    return 1;
}*/


//FUNCIÓN CONSTRUCTORA
/*Empleado* newUsuario()
{
    Empleado* retorno=NULL;
    Empleado* nuevoUsuario=(Empleado*)malloc(sizeof(Empleado));
    if(nuevoUsuario!=NULL)
    {
        strcpy(nuevoUsuario->nombre,"");
        nuevoUsuario->horasTrabajadas =0;
        nuevoUsuario->id =0;
        nuevoUsuario->sueldo =0;
        retorno = nuevoUsuario;
    }
    else
    {
          printf("Error no se consiguio memoria");
          exit(1);
    }
     return retorno;
}*/



//ORDENAR POR NOMBRE SE LO PASO A SORT


int ordenar(void* usuarioA,void* usuarioB)
{
    int returnAux=0;
    if(((eNumero*)usuarioA)->numero > ((eNumero*)usuarioB)->numero)
    {
        returnAux=1;
    }
    if(((eNumero*)usuarioA)->numero < ((eNumero*)usuarioB)->numero)
    {
        returnAux=-1;
    }
    return returnAux;
}

//MENU MODIFICA


int menuModifica()
{
    int opcion;

    system("cls");
    printf("1-Alta\n");
    printf("2-Genero\n");
    printf("3-Descripcion\n");
    printf("4-Duracion\n");
    printf("5-salir\n");

    printf("\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int cargarPersonas(ArrayList* listaUsuarios, char* path)
{
    FILE* f;
    eNumero* perAux;
    int cant;
    int retorno = -1;
    char numero [10];
    char nombre[50];
    char par [10];
    char impar [10];
    char primo [10];


    f = fopen(path, "r");
    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }

    while(!feof(f))
    {

        perAux = (eNumero*)malloc(sizeof(eNumero));
        if(perAux!=NULL)
        {
            if(feof(f))
            {
                break;
            }
            cant=fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^\n] \n", numero, nombre, par, impar, primo);

            if(cant == 5)
            {
                perAux->numero=atoi(numero);
                strcpy(perAux->nombre,nombre);
                perAux->par=atoi(par);
                perAux->impar=atoi(impar);
                perAux->primo=atoi(primo);
                listaUsuarios->add(listaUsuarios, perAux);
                retorno =0;

            }
            else
            {
                printf("error al leer con fscanf\n");
            }
        }
        else
        {
            printf("No se pudo leer el ultimo registro\n");
            break;
        }

    }
    fclose(f);
    return retorno;

}

void depurar(ArrayList* depurados)
{
    int i,j;
    int contador =0;
    eNumero* numero;
    eNumero* numeroDos;
    int borrado;

    for (i= 0; i<depurados->len(depurados); i ++)
    {
        numero= depurados->get(depurados,i);
        for (j=0; j< depurados->len(depurados); j ++)
        {
            numeroDos= depurados->get(depurados,j);
            if(numeroDos->numero == numero->numero)
            {
                borrado=depurados->remove(depurados,i);
                if(borrado == 0)
                {
                    depurados->remove(depurados,j);
                }
                break;
            }
        }

    }
}











