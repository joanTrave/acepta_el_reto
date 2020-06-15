/*
Acepta el reto 103: Problemas de herencia

Autor: Joan Travé Gordillo
*/
#include <stdio.h>
#include <math.h>

/* VALORES RESULTADO */
#define CAIN        "CAIN"
#define ABEL        "ABEL"
#define JUSTO       "JUSTO"

/* epsilon: Límite a partir del cual declaramos justa la repartición */
#define EPSILON     0.001

/* max_coef: El máximo numero de coeficientes que puede tener cada polinomio propuesto */
#define MAX_COEF    20

/*
FUNCIONES AUXILIARES

es_justo:           Dado el polinomio a evaluar y el numero de rectangulos, 
                    determina a quien es favorable.
evaluar_polinomio:  Dado un polinomio y un valor para las x, lo evalua.
*/
char* es_justo(int*, int, int);
float evaluar_polinomio(int*, int, float);

/* FUNCION PRINCIPAL */
int main()
{
    /*
    DECLARACION DE VARIABLES
    coef:           Array donde guardamos la posición de los coeficientes.
    n_coef:         El numero de coeficientes de cada caso.
    n_rectangulos:  El numero de rectangulos que queremos crear.
    */
    int coef[MAX_COEF];
    int n_coef, n_rectangulos;
    int i;

    /* Leemos el numero de coeficientes del polinomio */
    scanf("%d", &n_coef);

    while (!(n_coef == MAX_COEF))
    {
        /* Leemos los coeficientes */
        for(i = 0; i < n_coef + 1; i++)
        {
            scanf("%d", &coef[i]);
        }

        /* Leemos el numero de rectangulos */
        scanf("%d", &n_rectangulos);

        /* Escribimos el resultado por pantalla */
        printf("%s\n", es_justo(coef, n_coef, n_rectangulos));

        /* Leemos el numero de coeficientes del polinomio */
        scanf("%d", &n_coef);
    }
    

    return 0;
}


/* IMPLEMENTACION AUXILIARES */

char* es_justo(int* coef, int n_coef, int n_rectangulos)
{
    /* 
    DECLARACION DE VARIABLES
    i:          Auxiliar
    suma_cain:  Llevamos el computo total de la tierra de cain
    paso:       Cuanto mide un rectangulo en el eje de la x's
     */
    float i;
    float suma_cain = 0;
    float paso      = 1 / ((float) n_rectangulos);

    for(i = 0; i < 1 - paso; i += paso)
    {
        suma_cain += evaluar_polinomio(coef, n_coef, i) * paso;
    }

    /* Dictamos el veredicto */
    if (suma_cain > 0.5 + EPSILON)
    {
        return CAIN;
    }
    else if (suma_cain > 0.5 - EPSILON)
    {
        return JUSTO;
    }
    else
    {
        return ABEL;
    }
}


float evaluar_polinomio(int* coef, int n_coef, float punto)
{
    float total = 0;
    int i;

    for(i = 0; i <= n_coef; i++)
    {
        total += (float) coef[i] * pow(punto, n_coef - i);
    }

    return total;
}