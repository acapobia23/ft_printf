#include "ft_printf.h"

t_convs	convs_init(void)
{
	t_convs	convs;

	convs.info = info_init();
	convs.conv = '\0';
	return (convs);
}

t_value	*values_init(int len)
{
	t_value	*values;
	int		i;

	i = -1;
	values = NULL;
	values = malloc(len * sizeof(t_value));
	if (!values)
		return (NULL);
	while (++i < len)
	{
		values[i].arg = NULL;
		values[i].value = NULL;
		values[i].convs = convs_init();
	}
	return (values);
}

int	find_len_args(const char *format)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len++;
			if (format[i + 1] == '%')
				i++;
		}
		i++;
	}
	return (len);
}

t_data	*data_setup(const char *format)
{
	t_data	*data;

	data = NULL;
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->len = find_len_args(format);
	if (data->len == 0)
	{
		data->print_flag = false;
		data->values = NULL;
		return (data);
	}
	data->print_flag = true;
	data->values = values_init(data->len);
	if (!data->values)
	{
		free(data);
		return (NULL);
	}
	return (data);
}

t_info	info_init(void)
{
	t_info	info;

	info.valid = true;
	info.bonus = false;
	info.flags.minus = false;
	info.flags.zero = false;
	info.flags.point = false;
	info.flags.hashtag = false;
	info.flags.space = false;
	info.flags.plus = false;
	info.flags.error = false;
	info.flags.width = -1;
	info.flags.precision = -1;
	info.type.character = false;
	info.type.string = false;
	info.type.integer = false;
	info.type.pointer = false;
	info.type.hexadecimal = false;
	info.type.hexadecimal_up = false;
	info.type.uns_decimal = false;
	info.type.percent = false;
	info.type.no_type = false;
	return (info);
}
