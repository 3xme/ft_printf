#include <stdio.h>
#include "ft_printf.h"

int main()
{
	ft_printf("|%*p|", 4, (void *)0);
	printf("\n|%*p|", 4, (void *)0);
	return 0;
}