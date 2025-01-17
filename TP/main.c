#include <stdio.h>

int main(){
	/* EXEMPLE  CONST

	const int a = 4;
	a = 5;
	*/

	int a = 2;
	printf("%p\n", &a);
	int *p = &a;
	printf("%p\n", p);
	printf("%p\n", &p);
	*p = 5;
	printf("%d\n", a);

	return 0;
}