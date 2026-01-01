#include "ft_printf.h"

static void	precision_string(t_value *value)
{
	int		i;
	char	*tmp;

	i = value->convs.info.flags.precision;
	tmp = ft_substr((const char *)value->value, 0, (size_t)i);
	free(value->value);
	value->value = NULL;
	value->value = ft_strdup(tmp);
	free(tmp);
}

static void	make_precision(bool sign, t_value *value, char **zeros)
{
	char	*tmp;

	tmp = NULL;
	if (sign == true)
		(*zeros)[0] = '-';
	tmp = ft_strdup(value->value);
	if (!tmp)
		return ;
	free(value->value);
	value->value = NULL;
	value->value = ft_strjoin((const char *)(*zeros), tmp);
	if ((*zeros))
		free((*zeros));
	if (tmp)
		free(tmp);
}

static int	find_len(t_value *value)
{
	int	len;
	int	value_l;
	int	pre;

	value_l = ft_strlen(value->value);
	pre = value->convs.info.flags.precision;
	if (value->value[0] == '-')
	{
		value_l--;
		pre++;
	}
	if (value_l >= pre)
		return (-1);
	len = pre - value_l;
	return (len);
}

static void	precision_number(t_value *value)
{
	char	*zeros;
	int		len;
	int		i;
	bool	sign;

	zeros = NULL;
	sign = false;
	len = find_len(value);
	if (len == -1)
		return ;
	zeros = malloc((len + 1) * sizeof(char));
	if (!zeros)
		return ;
	zeros[len] = '\0';
	i = -1;
	if (value->value[0] == '-')
	{
		shift_one_char(&(value->value));
		sign = true;
	}
	else
		sign = false;
	while (++i < len)
		zeros[i] = '0';
	make_precision(sign, &(*value), &zeros);
}

void	precision_case(t_value *value)
{
	if (value->convs.info.flags.precision == 0)
	{
		free(value->value);
		value->value = NULL;
		value->value = ft_strdup("");
		return ;
	}
	if (value->convs.conv == 's')
		precision_string(&(*value));
	else
		precision_number(&(*value));
}
