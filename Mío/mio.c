#include <stdio.h>

/* DECLARACION DE FUNCIONES */

unsigned long int max (unsigned long int a, unsigned long int b)
{
    return (a > b) ? a : b;
}

unsigned long int min (unsigned long int a, unsigned long int b)
{
    return (a < b) ? a : b;
}

unsigned long int mcd (unsigned long int a, unsigned long int b)
{
    /* Calculamos el valor del minimo comun multiplo mediante */
    /* el algoritmo de euclides: */
    /* ENTRADA: a y b */
    /* SALIDA: Un mcd de a y b */
    /* 1- r0 <- a, r1 <- b */
    /* i = 1 */
    /* Mientras ri != 0: */
    /*  r(i+1) <- r(i-1) mod ri */
    /*  i <- i +1 */
    /* retornar r(i-1) */
    /* Fuente: wikipedia */
    
    /* Variable auxiliar para almacenar el residuo */
    unsigned long int r;
    
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    
    return a;
}


unsigned long int mcm (unsigned long int a, unsigned long int b)
{
    /* Funcion para calcular el mcm de dos numeros a y b */
    /* Se define como mcm(a, b) = ab/mcd(a, b) */
    /* Fuente: wikipedia */
    return (a / mcd (a, b)) * b;
}


/* FUNCION PRINCIPAL */
int main ()
{
    /* Para este problema se pide resolver: cuantos comunes multiples */
    /* se encuentran, de dos numeros M y D, menores que N, siendo M > N */
    /* y D < N. */
    /* Según mi conjetura, ese numero es truncado(N / mcm(M, D), aunque */
    /* a dia de hoy no he podido demostrarlo formalmente */
    
    /* DECLARACION DE VARIABLES */
    
    /* Se ha usado la nomenclatura de la descripcion */
    unsigned long int N, M, D;
    
    /* Variables auxiliares, para almacenar maximos y minimos */
    unsigned long int a, b;
    
    /* LOGICA DEL PROGRAMA */
    
    scanf ("%lu %lu %lu", &D, &M, &N);
    
    /* Leemos hasta que N = 0 */
    while (N || M || D)
    {
        /* Para que la funcion mcd tenga sentido, a < b */
        a = max (D, M);
        b = min (D, M);
        printf ("%lu\n", (N / mcm (a, b)));
        
        scanf ("%lu %lu %lu", &D, &M, &N);
    }
    
    return 0;
}
