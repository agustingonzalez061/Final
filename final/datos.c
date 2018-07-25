#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"
#include "ArrayList.h"
#include "datos.h"

void mostrarUsuario(eNumero* num)
{
    printf("%-20d%3s\t%3d\t%3d\t%3d\n",num->numero, num->nombre, num->par, num->impar, num->primo );
}

void mostrarTodos(ArrayList* num)
{
    int i;
    eNumero* unUsuario=newUsuario();
    unUsuario= num->get(num,1);
    printf("Numero     Nombre                    par    impar  primo\n\n");
    mostrarUsuario(unUsuario);
    system("pause");
    for(i=0; i<num->len(num); i++)
            {
                if(i== 33 || i == 66 || i == 99 || i == 132 || i == 165 || i== 198 || i == 231 || i == 264 || i == 297 || i== 330 || i == 363 || i == 396 || i == 429 || i == 462)
                {
                    system("pause");
                }
                unUsuario= num->get(num,i);
                mostrarUsuario(unUsuario);
            }
}

//FUNCIÓN CONSTRUCTORA
eNumero* newUsuario()
{
    eNumero* retorno=NULL;
    eNumero* nuevoUsuario=(eNumero*)malloc(sizeof(eNumero));
    if(nuevoUsuario!=NULL)
    {
        strcpy(nuevoUsuario->nombre,"");
        nuevoUsuario->numero=0;
        nuevoUsuario->par=0;
        nuevoUsuario->impar=0;
        nuevoUsuario->primo=0;
        retorno = nuevoUsuario;
    }
    else
    {
          printf("Error no se consiguio memoria");
          exit(1);
    }
     return retorno;
}

void vali1(ArrayList* num)
{
    int i,j;
    int a;
    eNumero *numer;

        for(i=0; i<num->len(num); i++)
            {
                a=0;
                numer=num->get(num,i);
                if((numer->numero)%2 ==0 && numer->numero !=0)
                {
                    numer->par =1;
                }
                else
                {
                    numer->impar =1;
                }
               /* for (j=0;j<=numer->numero;j++)
                {
                    if((numer->numero)%j==0)
                    {
                        a++;
                    }
                }
                if(a==2)
                {
                    numer->primo =1;
                }*/
           }
}
