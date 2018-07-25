#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"
#include "ArrayList.h"

typedef struct
{
    int numero;
    char nombre[50];
    int par;
    int impar;
    int primo;
}eNumero;


 void mostrarUsuario(eNumero* unnuemro);
 void mostrarTodos(ArrayList* num);
 eNumero* newUsuario();
 void vali1(ArrayList*);
