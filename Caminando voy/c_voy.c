/*  ACEPTA EL RETO: CAMINANDO VOY */
/* Solucion propuesta por el usuario yuan_t, 5a posicion en el momento de hacer la entrega */
/* @dzerkuv en telegram */
#include <stdio.h>

/* Expresion macro que devuelve la diferencia de dos segmentos */
#define DIF(a, b) ( b - a )

/* FUNCION PRINCIPAL */
int main()
{
    /* Variables auxiliares: */
    /* i: para iterar en el bucle for */
    /* cota_anterior: ultim cota que se leyó */
    /* cota_actual: cota actual */
    /* suma_actual: suma actual de segmentos */
    /* dif: la diferencia actual entre cotas */
    int i, cota_anterior, cota_actual, suma_actual, dif;
    
    /* D: Maximo desnivel acumulable */
    /* N: Numero de cotas a leer */
    int D, N;
    
    /* Mientras el retorno de la funcion scanf sea mayor que 0, es decir, */
    /* se estén leyendo datos */
    while (scanf("%d %d", &D, &N) >= 0)
    {
        /* Reiniciamos el valor de la suma actual al empezar el bucle */
        suma_actual = 0;
        scanf("%d", &cota_actual);
        
        for (i = 1; i < N && suma_actual <= D; i++)
        {
            /* Actualizamos el valor de las cotas */
            cota_anterior = cota_actual;
            scanf("%d", &cota_actual);
            
            dif = DIF(cota_anterior, cota_actual);
            
            /* Si estamos en un tramo creciente, actualizamos la suma, */
            /* si no, la reiniciamos */
            if (dif > 0)
                suma_actual += dif;
            else
                suma_actual = 0;
        }
        
        if (suma_actual > D)
        {
            printf("NO APTA\n");
            /* Seguimos leyendo hasta final de linea */
            while (getchar_unlocked() != '\n');
        }
        else
            printf("APTA\n");
        
    }
    
    return 0;
}
