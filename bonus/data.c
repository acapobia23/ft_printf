#include "ft_printf.h"

void	free_data(t_data **data)
{
	int		i;

	i = -1;
	if (!(*data) || !data)
		return ;
	while (++i < (*data)->len)
	{
		if ((*data)->values)
		{
			if ((*data)->values[i].arg && (*data)->values[i].convs.conv != 's')
				free((*data)->values[i].arg);
			if ((*data)->values[i].value)
				free((*data)->values[i].value);
		}
	}
	if ((*data)->values)
		free((*data)->values);
	if ((*data))
		free((*data));
}

static void	args_setup(t_value *value, va_list args)
{
	char	c;
	long	*tmp;

	tmp = NULL;
	c = value->convs.conv;
	if (c == 's')
		value->arg = (void *)va_arg(args, char *);
	else if (c == '%')
		value->arg = (void *)ft_strdup("%");
	else if (ft_strchr("idcuxXp", c))
	{
		tmp = malloc(sizeof(long));
		if (!tmp)
			return ;
		if (ft_strchr("%idc", c))
			*tmp = va_arg(args, int);
		else if (ft_strchr("uxX", c))
			*tmp = va_arg(args, unsigned int);
		else if (c == 'p')
			*tmp = va_arg(args, unsigned long);
		value->arg = (void *)tmp;
	}
}

static void	create_value(char **mtx_args, t_data **data, va_list args)
{
	int	i;

	i = -1;
	while (++i < (*data)->len)
	{
		convs_setup(&((*data)->values[i]), mtx_args[i]);
		if (check_valid_args(&((*data)->values[i]), mtx_args[i]) == -1)
		{
			(*data)->values[i].arg = NULL;
			(*data)->values[i].value = ft_strdup((const char *)mtx_args[i]);
			(*data)->values[i].convs.info.valid = false;
		}
		else
			args_setup(&((*data)->values[i]), args);
	}
}

t_data	*init_data(const char *format, va_list args)
{
	char	**mtx_args;
	t_data	*data;

	data = data_setup(format);
	if (!data)
		return (NULL);
	if (data->print_flag == false)
		return (data);
	mtx_args = mtx_args_init(format, data->len);
	if (!mtx_args)
	{
		free_data(&data);
		return (NULL);
	}
	create_value(mtx_args, &data, args);
	free_mtx(mtx_args);
	return (data);
}
