#include <stdio.h>

int main()
{
	char c = 'a';
	int i = 2;
	double d = 10.5;
	short s = 100;

	printf("size of c: %zu bytes\n", sizeof(c));
	printf("size of i: %zu bytes\n", sizeof(i));
        printf("size of d: %zu bytes\n", sizeof(d));
        printf("size of s: %zu bytes\n", sizeof(s));

	printf("address of c: %p\n", (void*)&c);
	printf("address of i: %p\n", (void*)&i);
	printf("address of d: %p\n", (void*)&d);
	printf("address of s: %p\n", (void*)&s);
	return 0;
}
