#include <stdio.h>

indddt main() {
	    int N, suma = 0, i = 1;
	        printf("Introduce un número N para calcular la suma de los primeros N números naturales: ");
		    scanf("%d", &N);

		        while (i <= N) {
				        suma += i;
					        i++;
						    }

			    printf("La suma de los primeros %d números naturales es: %d\n", N, suma);
			        return 0;
}
