/*
 * Programa que corresponde al problema de aceptaelreto.com llamado Resistencias
 * en serie. Se trata de sumar resistencias proporcionadas por un archivo de
 * texto.
 * 
 * EXPONIENTES
 * 
 * o  -> 0,
 * da -> 1, 
 * h  -> 2, 
 * k  -> 3, 
 * M  -> 6, 
 * G  -> 9
 * 
 * Autor: Joan Travé Gordillo
 * www.joantrave.com
 */
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_CHAR 3


/* DECLARACION DE FUNCIONES AUXILIARES */
int get_index(char*);
char* get_name_index(int);
int get_zeros_n(int);
int get_valid_index(int);


/* FUNCION PRINCIPAL */
int main()
{
    /* DECLARACION DE VARIABLES */
    /* n: numero de pruebas a realizar */
    /* valor_serie: registre donde actualizaremos el valor total */
    /* valor_min_index_serie: exponente del minimo indice */
    unsigned int n, valor_serie;
    int valor_min_index_serie;
    
    /* VARIABLES AUXILIARES */
    /* valor_aux: valor relativo de cada resistencia leida */
    /* index_aux: valor del indice de cada resistencia leida */
    int valor_aux, index_aux, valid_index_aux;
    
    /* nombre_aux: nombre de cada resistencia leida */
    char nombre_aux[MAX_CHAR];
    
    /* Primero leemos el numero de experimentos a procesar */
    scanf("%d", &n);
    
    while(n > 0)
    {
        /* Al principio el valor de la serie es 0 y */
        /* el minimo indice es lo maximo que puede valer: 9 */
        valor_serie             = 0;
        valor_min_index_serie   = 9;
        
        scanf("%d", &valor_aux);
        while(valor_aux != 0)
        {
            scanf("%s", nombre_aux);
            
            /* Calculamos el valor del indice leido */
            index_aux       = get_index(nombre_aux);
            valid_index_aux = get_valid_index(index_aux + get_zeros_n(valor_aux));
            
            if(index_aux < valor_min_index_serie)
            {
                /* Si el nuevo indice es menor que el minimo, actualizamos */
                //valor_serie *= pow(10, valid_index_aux - valor_min_index_serie);
                valor_serie *= pow(10, valor_min_index_serie - valid_index_aux);
                valor_min_index_serie = valid_index_aux;
            }
            
            /* Reescalamos el valor acorde al indice calculado */
            valor_aux /= pow(10, valor_min_index_serie - index_aux);
            
            /* actualizamos el valor total del experimento */
            valor_serie += valor_aux;
            printf("Vals: aux: %d serie: %d index: %d valid: %d min: %d\n", valor_aux, valor_serie, index_aux, valid_index_aux, valor_min_index_serie);
            
            scanf("%d", &valor_aux);
        }
        
        /* Imprimimos el  */
        printf("%d %s\n", valor_serie, get_name_index(valor_min_index_serie));
        
        /* Disminuimos el numero de experimentos que quedan por procesar */
        n--;
    }
    
    return 0;
}


/* FUNCIONES AUXILIARES */
int get_index(char* nombre_indice)
{
    /* Dado el nombre de un indice devolvemos el valor de su exponente */
    
    /* exponente: numero de zeros en la cola del numero */
    int exponente = 0;
    
    switch(nombre_indice[0])
    {
        case 'o':
            exponente += 0;
            break;
        case 'd':
            exponente += 1;
            break;
        case 'h':
            exponente += 2;
            break;
        case 'k':
            exponente += 3;
            break;
        case 'M':
            exponente += 6;
            break;
        case 'G':
            exponente += 9;
            break;
        default:
            break;
    }
    
    return exponente;
}


int get_valid_index(int exponente)
{
    /* Devuelve el exponente valido, dado un exponente  */
    if(exponente > 3 && exponente < 9)
        exponente = 6;
    else if(exponente >= 9)
        exponente = 9;
    
    return exponente;
}


char* get_name_index(int index)
{
    /* Dado el exponente de un numero, devuelve la notacion correcta */
    switch(index)
    {
        case 0:
            return "o";
        case 1:
            return "da";
        case 2:
            return "h";
        case 3:
            return "k";
        case 6:
            return "M";
        case 9:
            return "G";
        default:
            break;
    }
    return "-";
}


int get_zeros_n(int n)
{
    /* Dado un numero n devuelve el numero de zeros que tiene en su cola */
    if ((n % 10) == 0)
        return 1 + get_zeros_n(n / 10);
    else
        return 0;
}


