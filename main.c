#include <stdio.h>
#include "ft_printf.h"

int main()
{
	ft_printf("\n|%05.2x|", 255);
	printf("\n|%05.2x|", 255);
	return 0;
}