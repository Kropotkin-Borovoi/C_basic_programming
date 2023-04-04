#include <stdio.h>
#include <math.h>

int main() 
{
	printf ("This program prints the number Pi up to the sign requested\
 by the user\nEnter the number up to which you want to calculate\
 the number Pi\n");
	int accuracy = 0, n = 1, i=0;
	
	float accuracy_limit = 10, S1 = 0, S2 = 0, S = 0;
	
	scanf ("%d", &accuracy);
	
	do {
		S1 = (float) 4 / n;//высчитывается первый член
		n += 2;
		S2 = (-1) * ((float) 4 / n);//высчитывается второй член
		n += 2;
		S = S1 + S2 + S;
		i += 2;
	}
	while (S1> pow(accuracy_limit, -accuracy-2));//когда член будет
//много меньше нашей точности, то прекращается вычисдение
	
	printf ("%f\n\n", round(S / pow(accuracy_limit, -accuracy)) *\
 pow(accuracy_limit, -accuracy));
	
	printf ("%d\n\n", i);
	
	return 0;
}


