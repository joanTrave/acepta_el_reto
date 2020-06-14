/*
Acepta el reto 102

Encriptacion de mensajes

Autor: Joan Travé Gordillo
*/
#include <stdio.h>
#include <string.h>

#define CADENA_SALIDA "pFIN"
#define MAX_CHAR 4096


/*
FUNCIONES AUXILIARES

descodificar_cadena:    Dada una cadena de caracteres y una posicion actual
                        devuelve el numero de vocales sin acento
es_vocal_sin_acento:    Dado un caracter ascii devuelve 1 si es una vocal sin
                        acento, 0 de cualquier otra forma
es_caracter_especial:   Dado un caracter devuelve uno si no es ninguna letra
                        y 0 si sí lo es
*/
int descodificar_cadena(char pos_actual, char* cadena);
int es_vocal_sin_acento(char c);
int es_caracter_especial(char c);


/* FUNCION PRINCIPAL */
int main(int argc, char const *argv[])
{
    /* DECLARACION DE VARIABLES */
    char *linea_leida = NULL;
    size_t len = 0;
    int n_vocales_sin_acento;
    int fin_encontrado = 0;

    getline(&linea_leida, &len, stdin);

    while (!fin_encontrado)
    {
        /* Descodificamos la cadena */
        n_vocales_sin_acento = descodificar_cadena(linea_leida[0], linea_leida);

        /* Si la cadena equivale a la cadena que marca el final, salimos */
        if(!strcmp(linea_leida, CADENA_SALIDA))
        {
            fin_encontrado = 1;
        }
        else
        {
            printf("%d\n", n_vocales_sin_acento);

            /* Leer una nueva linea */
            getline(&linea_leida, &len, stdin);
        }
    }
    
    return 0;
}

int descodificar_cadena(char pos_actual, char* cadena)
{
    /* DECLARACION DE VARIABLES */
    int suma    = 0;
    char offset = 'p' - pos_actual;
    char offset_el;
    int len     = strlen(cadena);
    int i;

    for (i = 0; i < len; i++)
    {
        if(!es_caracter_especial(cadena[i]))
        {
            offset_el = (cadena[i] < 'Z' + 1) ? 'A' : 'a';

            cadena[i] -= offset_el;
            cadena[i] = (cadena[i] + offset) % ('z' - 'a' + 1);
            cadena[i] += offset_el;
            
            suma += es_vocal_sin_acento(cadena[i]);
        }
    }

    return suma;
}


int es_caracter_especial(char c)
{
    if(
        (c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z')
    )
    {
        return 0;
    }
    return 1;
}


int es_vocal_sin_acento(char c)
{
    /* Si equivale a alguna vocal devolvemos 1 */
    if(
        c == 'A' || c == 'a' ||
        c == 'E' || c == 'e' ||
        c == 'I' || c == 'i' ||
        c == 'O' || c == 'o' ||
        c == 'U' || c == 'u'
    )
    {
        return 1;
    }
    /* 0 en cualquier otro caso */
    return 0;
}