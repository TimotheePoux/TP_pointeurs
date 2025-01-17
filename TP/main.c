#include <stdio.h>

void min_max(int tab[], int size, int* min, int* max)
{
	if (size < 1)
	{
		return;
	}
	*min = tab[0];
	*max = tab[0];
	for (int i = 0; i < size; i++)
	{
		if (*min > tab[i])
		{
			*min = tab[i];
		}
		if (*max < tab[i])
		{
			*max = tab[i];
		}
	}
}

int main(){
	/* EXEMPLE  CONST

	const int a = 4;
	a = 5;
	*/

	/* EXEMPLE 1 POINTEURS
	
	int a = 2;
	printf("%p\n", &a);
	int *p = &a;
	printf("%p\n", p);
	printf("%p\n", &p);
	*p = 5;
	printf("%d\n", a);
	*/

	int min = 0;
	int max = 0;
	int tableau[] = {12, 2 , 8 , -7 , 15 , 2};
	min_max(tableau, 6, &min, &max);
	printf("min = % d, max = % d\n", min, max);

	return 0;
}