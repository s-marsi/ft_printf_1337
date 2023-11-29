#include "ft_printf.h"

int main()
{
	int a;
	printf("\ncount :  %d",ft_printf("%% hello %c %s %d %i %u %X %x %p", 'A', "SOUFYANE", INT_MIN, INT_MAX, UINT_MAX, 15258, 78965, &a));
	printf("\n");
	printf("\ncount :  %d",   printf("%% hello %c %s %d %i %u %X %x %p", 'A', "SOUFYANE", INT_MIN, INT_MAX,  UINT_MAX, 15258, 78965, &a));
}