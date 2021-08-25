/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>

char c1;		// elements initialized to 0
static char c2;	// elements initialized to 0
/*
void zero(void)
{
	char c5 = 0;
	char c3;	// elements have indeterminate value!
	static char c4;	// elements initialized to 0

	printf("%d \n", c5 == 0);
	printf("%d \n", c5 == '\0');
	printf("%d \n", c1 == 0);
	printf("%d \n", c1 == '\0');
	printf("%d \n", c2 == 0);
	printf("%d \n", c2 == '\0');
	printf("%d \n", c3 == 0);
	printf("%d \n", c3 == '\0');
	printf("%d \n", c4 == 0);
	printf("%d \n", c4 == '\0');
	printf("%d \n", 0 == '\0');
}

int main()
{
	int i = 48;
	char c = '0';
	char c1 = (char)i;
	int i1 = (int)c1;
	if ((int)c == (char)i) {
		printf("t");
	}
	if (i1 == c1) {
		printf("t");
	}

	zero();

	system("pause");

	return 0;
}

/**/