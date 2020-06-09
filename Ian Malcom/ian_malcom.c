/*
Acepta el reto de la semana de 08/06/2020 a 14/06/2020

Los calcetines de Ian Malcom

Autor: Joan Travé Gordillo
*/
#include <stdio.h>

#define EMPAREJADOS "EMPAREJADOS"
#define NEGRO_SOLITARIO "NEGRO SOLITARIO"
#define GRIS_SOLITARIO "GRIS SOLITARIO"
#define PAREJA_MIXTA "PAREJA MIXTA"


typedef struct _calcetines {
    /* Estructura que emula el conjunto de calcetines */
    /* *_emparejado está emparejado si vale 1 y no si vale -1 */
    int gris_emparejado;
    int negro_emparejado;
    /* Optimizaciones futuras: estudiar si alineamiento. */
} calcetines;

/* FUNCIONES AUXILIARES */
void init_calcetines(calcetines* c);
void update_calcetines(calcetines* c, char tipo);
char* get_resultado(calcetines c);


int main()
{
    /* DECLARACION DE VARIABLES */
    char calcetin;
    calcetines c;

    /* Leemos el primer caracter del fichero */
    scanf("%c", &calcetin);

    /* Se acaban los casos cuando leemos un "." como primer caracter */
    while (calcetin != '.')
    {
        init_calcetines(&c);

        /* Tratar todos los casos */
        do
        {
            /* Identificamos el caracter leido */
            update_calcetines(&c, calcetin);
            
            /* Leemos el siguiente caracter */
            scanf(" %c", &calcetin);
        } while (calcetin != '.');

        /* Escribimos el resultado de la linea */
        printf("%s\n", get_resultado(c));
        

        /* Leemos el primer caracter de la siguiente linea */
        scanf("\n%c", &calcetin);
    }
    
    return 0;
}


/* IMPLEMENTACION DE LAS FUNCIONES AUXILIARES */
void init_calcetines(calcetines* c)
{
    c->gris_emparejado  = 1;
    c->negro_emparejado = 1;
}

void update_calcetines(calcetines* c, char tipo)
{
    if(tipo == 'N')
    {
        c->negro_emparejado *= -1;
    }
    else if(tipo == 'G')
    {
        c->gris_emparejado *= -1;
    }
}

char* get_resultado(calcetines c)
{
    if(c.gris_emparejado == c.negro_emparejado)
    {
        if (c.gris_emparejado < 0)
        {
            return PAREJA_MIXTA;
        }
        else
        {
            return EMPAREJADOS;
        }
    }
    else
    {
        if (c.gris_emparejado < 0)
        {
            return GRIS_SOLITARIO;
        }
        else
        {
            return NEGRO_SOLITARIO;
        }
    }
}
