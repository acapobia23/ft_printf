#include "ft_printf.h"

static int	check_return(int check, char c, t_value *value)
{
	if (check == -1)
	{
		value->convs.info.valid = false;
		return (-1);
	}
	if (ft_strchr("cspdiuxX%", c) == NULL)
	{
		value->convs.info.valid = false;
		return (-1);
	}
	return (0);
}

static int	check_point(char *args, int i)
{
	if (ft_isdigit(args[i]) == 0)
		return (-1);
	return (0);
}

static int	check_double(char *args, int i)
{
	char	c;
	int		count;
	int		j;

	count = 0;
	j = 1;
	c = args[i];
	while (args[j] && ft_strchr("0-# +", args[j]))
	{
		if (c == args[j])
			count++;
		j++;
	}
	if (count != 1)
		return (-1);
	return (0);
}

int	check_valid_args(t_value *value, char *args)
{
	int		i;
	char	check;

	i = 1;
	check = 0;
	if (value->convs.info.valid == false)
		return (-1);
	while (args[i] && ft_strchr("0-# +", args[i]))
	{
		check = check_double(args, i);
		i++;
	}
	while (ft_isdigit(args[i]))
		i++;
	if (args[i] == '.')
	{
		i++;
		if (check_point(args, i) == -1)
			return (check_return(-1, args[i], &(*value)));
		while (ft_isdigit(args[i]))
			i++;
	}
	return (check_return(check, args[i], &(*value)));
}
