/*
Acepta el reto numero 100

Constante de Kaprekar


1- Elige un número de cuatro dígitos que tenga al menos dos diferentes (es 
   válido colocar el dígito 0 al principio, por lo que el número 0009 es válido).
2- Coloca sus dígitos en orden ascendente y en orden descendente para formar
   dos nuevos números. Puedes añadir los dígitos 0 que necesites al principio.
3- Resta el menor al mayor.
4- Vuelve al paso 2.


Autor: Joan Trave Gordillo
*/
#include <stdio.h>
#include <stdlib.h>

/* La constante de kaprekar */
#define KAPREKAR 6174

/* El numero de digitos de cada numero */
#define DIGITS 4


/*
FUNCIONES AUXILIARES

sort_int_asc:       Dado un entero de 4 cifras retorna este con las cifras
                    ordenadas en orden ascendente: 6174 -> 1467
sort_int_desc:      Dado un entero de 4 cifras retorna este con las cifras
                    ordenadas en orden descendente: 6174 -> 7641
kaprekar_it:        Dado un entero devuelve el numero de iteraciones hasta 
                    dar con el numero de kaprekar o 0 si no se pudo
kaprekar_invalid:   Dado un entero devuelve 1 si va a ser imposible dar con
                    el numero de kaprekar: 1111, 2222...
list_to_int:        Dado una lista de 4 digitos lo convierte en un entero de
                    la siguiente manera: {4, 5, 8, 9} -> 4589
*/
int sort_int_asc(int);
int sort_int_desc(int);
int kaprekar_it(int);
int kaprekar_invalid(int);
int list_to_int(int*);


/* FUNCION PRINCIPAL */
int main(int argc, char const *argv[])
{
    /* VARIABLES AUXILIARES */
    /* n: Numero de iteraciones */
    /* l: Caso de cada linea */
    int n, l;

    /* Leemos el numero de casos */
    scanf("%d", &n);
    /* Para cada caso */
    while(n > 0)
    {
        /* Leemos la nueva linea */
        scanf("%d", &l);
        /* Escribimos el resultado */
        printf("%d\n", kaprekar_it(l));
        n--;
    }
    return 0;
}


/* Implementacion de las funciones auxiliares */

int compare_asc(const void *_a, const void *_b) {
 
        int *a, *b;
        
        a = (int *) _a;
        b = (int *) _b;
        
        return (*b - *a);
}

int compare_desc(const void *_a, const void *_b) {
 
        int *a, *b;
        
        a = (int *) _a;
        b = (int *) _b;
        
        return (*a - *b);
}

int sort_int_asc(int n)
{
    int lista_e[4] = {0, 0, 0, 0};
    int i          = 0;

    while (n != 0)
    {
        lista_e[i] = n % 10;
        n /= 10;
        i++;
    }
    

    qsort(lista_e, DIGITS, sizeof(int), &compare_asc);
    return list_to_int(lista_e);
}

int sort_int_desc(int n)
{
    int lista_e[4] = {0, 0, 0, 0};
    int i          = 0;

    while (n != 0)
    {
        lista_e[i] = n % 10;
        n /= 10;
        i++;
    }

    qsort(lista_e, DIGITS, sizeof(int), &compare_desc);
    return list_to_int(lista_e);
}

int kaprekar_it(int n)
{
    /* VARIABLES AUXILIARES */
    /* i: numero de iteraciones */
    int i = 0;

    /* Si es invalido devolvemos 0 */
    if(kaprekar_invalid(n) != 0)
    {
        return 8;
    }

    /* Mientras no logremos KAPREKAR, procedemos */
    while (n != KAPREKAR)
    {
        n = sort_int_desc(n) - sort_int_asc(n);
        i++;
    }

    return i;
}

int kaprekar_invalid(int n)
{
    /* VARIABLES AUXILIARES */
    /* last: ultimo digito leido */
    /* aux: penultimo digito leido */
    int last = n % 10;
    int aux, i;

    for(i = 1; i < DIGITS; i++)
    {
        /* Avanzamos un digito */
        n /= 10;

        /* Guardamos el ultimo digito */
        aux = n % 10;

        /* Comparamos los dos ultimos */
        if(aux != last)
        {
            return 0;
        }

        last = aux;
    }

    return 1;
}

int list_to_int(int* list)
{
    return list[0] + list[1] * 10 + list[2] * 100 + list[3] * 1000;
}