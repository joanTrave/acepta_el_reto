#include <stdio.h>

#define MAX(a, b) ( a > b ? a : b )
#define ABS(a) ( a >= 0 ? a : -1 * a )

int main()
{
    int i, j;
    int casos, dado_1, dado_2;
    int num_respuestas, max;
    
    scanf("%d", &casos);
    
    for(i = 0; i < casos; i++)
    {
        scanf("%d %d", &dado_1, &dado_2);
        num_respuestas = ABS((dado_1 - dado_2));
        max = MAX(dado_1, dado_2) - num_respuestas + 1;
        
        printf("%d", max);
        for (j = 1; j <= num_respuestas; j++)
			printf(" %d", max + j);
		printf("\n");
	}
	
	return 0;
}
