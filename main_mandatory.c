#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int		ret1;
	int		ret2;
	int		n;
	unsigned int	u;
	char		*str;

	n = -42;
	u = 42;
	str = "hello";

	printf("===== TEST c =====\n");
	ret1 = ft_printf("ft : %c\n", 'A');
	ret2 = printf   ("og : %c\n", 'A');
	printf("ret ft=%d | og=%d\n\n", ret1, ret2);

	printf("===== TEST s =====\n");
	ret1 = ft_printf("ft : %s\n", str);
	ret2 = printf   ("og : %s\n", str);
	printf("ret ft=%d | og=%d\n\n", ret1, ret2);

	printf("===== TEST d / i =====\n");
	ret1 = ft_printf("ft : %d | %i\n", n, n);
	ret2 = printf   ("og : %d | %i\n", n, n);
	printf("ret ft=%d | og=%d\n\n", ret1, ret2);

	printf("===== TEST u =====\n");
	ret1 = ft_printf("ft : %u\n", u);
	ret2 = printf   ("og : %u\n", u);
	printf("ret ft=%d | og=%d\n\n", ret1, ret2);

	printf("===== TEST x / X =====\n");
	ret1 = ft_printf("ft : %x | %X\n", u, u);
	ret2 = printf   ("og : %x | %X\n", u, u);
	printf("ret ft=%d | og=%d\n\n", ret1, ret2);

	printf("===== TEST p =====\n");
	ret1 = ft_printf("ft : %p\n", str);
	ret2 = printf   ("og : %p\n", str);
	printf("ret ft=%d | og=%d\n\n", ret1, ret2);

	printf("===== TEST %% =====\n");
	ret1 = ft_printf("ft : %%\n");
	ret2 = printf   ("og : %%\n");
	printf("ret ft=%d | og=%d\n\n", ret1, ret2);

	return (0);
}
