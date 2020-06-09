#include <stdio.h>

//#include <iostream>

/* Expresion macro que devuelve la diferencia de dos segmentos */
#define DIF(a, b) ( b - a )

void fastscan(int &number) 
{ 
    //variable to indicate sign of input number 
    bool negative = false; 
    int c; 
  
    number = 0; 
  
    // extract current character from buffer 
    c = getchar_unlocked();
    if (c=='-') 
    { 
        // number is negative 
        negative = true; 
  
        // extract the next character from the buffer 
        c = getchar_unlocked();
    } 
  
    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=getchar_unlocked()) 
        number = number *10 + c - 48; 
  
    // if scanned input has a negative sign, negate the 
    // value of the input number 
    if (negative) 
        number *= -1; 
}

/* FUNCION PRINCIPAL */
int main()
{
    /* Variables auxiliares: */
    /* i: para iterar en el bucle for */
    /* cota_anterior: ultim cota que se leyó */
    /* cota_actual: cota actual */
    /* suma_actual: suma actual de segmentos */
    /* dif: la diferencia actual entre cotas */
    /* c: para leer hasta fin de linea */
    int i, cota_anterior, cota_actual, suma_actual, dif, c;
    
    /* D: Maximo desnivel acumulable */
    /* N: Numero de cotas a leer */
    int D, N;
    
    /* Mientras el retorno de la funcion scanf sea mayor que 0, es decir, */
    /* se estén leyendo datos */
    while (scanf("%d %d\n", &D, &N) >= 0)
    {
        /* Reiniciamos el valor de la suma actual al empezar el bucle */
        suma_actual = 0;
        fastscan(cota_actual);
        
        //std::cout << cota_actual << " ";
        
        for (i = 1; i < N && suma_actual <= D; i++)
        {
            /* Actualizamos el valor de las cotas */
            cota_anterior = cota_actual;
            fastscan(cota_actual);
            
            //std::cout << cota_actual << " ";
            
            dif = DIF(cota_anterior, cota_actual);
            
            /* Si estamos en un tramo creciente, actualizamos la suma, */
            /* si no, la reiniciamos */
            if (dif > 0)
                suma_actual += dif;
            else
                suma_actual = 0;
        }
        
        while ((c = getchar_unlocked()) != '\n'  && c != '\0');
        
        if (suma_actual > D)
        {
            printf("NO APTA\n");
        }
        else
            printf("APTA\n");
        
    }
    
    return 0;
}
