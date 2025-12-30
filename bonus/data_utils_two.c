#include "ft_printf.h"

static char	turn_char_type(t_type type)
{
	char	conv;

	if (type.character == true)
		conv = 'c';
	else if (type.string == true)
		conv = 's';
	else if (type.pointer == true)
		conv = 'p';
	else if (type.integer == true)
		conv = 'i';
	else if (type.uns_decimal == true)
		conv = 'u';
	else if (type.hexadecimal == true)
		conv = 'x';
	else if (type.hexadecimal_up == true)
		conv = 'X';
	else if (type.percent == true)
		conv = '%';
	else
		conv = '\0';
	return (conv);
}

static void	set_conv(t_type *type, char c)
{
	if (c == 'c')
		type->character = true;
	else if (c == 's')
		type->string = true;
	else if (c == 'p')
		type->pointer = true;
	else if (c == 'i' || c == 'd')
		type->integer = true;
	else if (c == 'u')
		type->uns_decimal = true;
	else if (c == 'x')
		type->hexadecimal = true;
	else if (c == 'X')
		type->hexadecimal_up = true;
	else if (c == '%')
		type->percent = true;
	else
		type->no_type = true;
}

static void	set_flags(t_flags *flags, char *c)
{
	if (*c == '-')
		flags->minus = true;
	else if (*c == '0' && flags->width == -1 && flags->point == false)
		flags->zero = true;
	else if (*c == '.')
		flags->point = true;
	else if (*c == '#')
		flags->hashtag = true;
	else if (*c == ' ')
		flags->space = true;
	else if (*c == '+')
		flags->plus = true;
	else if (ft_isdigit(*c) && flags->point == true && flags->precision == -1)
		flags->precision = ft_atoi((const char *)c);
	else if (ft_isdigit(*c) && flags->point == false && flags->width == -1)
		flags->width = ft_atoi((const char *)c);
	else
		flags->error = true;
}

static int	check_len(char *arg, t_value *value)
{
	if (ft_strlen((const char *)arg) == 1)
	{
		value->convs.info.valid = false;
		return (-1);
	}
	return (0);
}

void	convs_setup(t_value *value, char *arg)
{
	int	i;

	i = 0;
	if (check_len(arg, &(*value)) == -1)
		return ;
	while (arg[++i])
	{
		if (ft_strchr("-0.# +", arg[i]) || ft_isdigit(arg[i]) != 0)
		{
			value->convs.info.bonus = true;
			set_flags(&value->convs.info.flags, &arg[i]);
		}
		else if (ft_strchr("cspdiuxX%", arg[i]))
		{
			set_conv(&value->convs.info.type, arg[i]);
			value->convs.conv = turn_char_type(value->convs.info.type);
		}
		else
		{
			value->convs.conv = arg[i];
			value->convs.info.valid = false;
			return ;
		}
	}
}
