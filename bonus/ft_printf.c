#include "ft_printf.h"

static int	put_char(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	put_str(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		put_char(s[i]);
	return (i);
}

static void	skip_value(int *i, const char *format, t_value values)
{
	if (format[*i] == '%')
		(*i)++;
	if (values.convs.conv == 'i')
	{
		while (format[*i] != 'i' && format[*i] != 'd' && format[*i] != '%')
			(*i)++;
	}
	else
	{
		while (format[*i] != values.convs.conv)
			(*i)++;
	}
}

static int	print_all(const char *format, t_data *data)
{
	int	i;
	int	c;
	int	tot;

	i = 0;
	c = 0;
	tot = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			tot += put_str(data->values[c].value);
			skip_value(&i, format, data->values[c]);
			c++;
		}
		else
			tot += put_char(format[i]);
		i++;
	}
	return (tot);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		tot;
	t_data	*data;

	if (!format || !format[0])
		return (0);
	va_start(args, format);
	data = init_data(format, args);
	va_end(args);
	if (!data || data->print_flag == false)
	{
		if (data)
			free_data(&data);
		return (put_str((char *)format));
	}
	check_flag_comb(&data);
	transform_value(&(data->values), data->len);
	tot = print_all(format, data);
	free_data(&data);
	return (tot);
}
