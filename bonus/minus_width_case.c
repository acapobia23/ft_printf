#include "ft_printf.h"

static void	right_align(char **str, char **bonus)
{
	char	*tmp;

	if (!(*bonus))
	{
		(*bonus) = ft_strdup((const char *)(*str));
		free((*str));
		return ;
	}
	tmp = ft_strjoin((const char *)(*str), (const char *)(*bonus));
	free((*str));
	if (!tmp)
		return ;
	free((*bonus));
	(*bonus) = NULL;
	(*bonus) = tmp;
}

static void	left_align(char **str, t_value **value)
{
	char	*tmp;

	tmp = ft_strjoin((const char *)(*value)->value, (const char *)(*str));
	free((*str));
	if (!tmp)
		return ;
	free((*value)->value);
	(*value)->value = NULL;
	(*value)->value = tmp;
}

static char	*str_align(t_value **value, char *bonus)
{
	char	*str;
	int		len;
	int		i;
	int		width;
	int		l_val;

	i = -1;
	width = (*value)->convs.info.flags.width;
	if (width == 0)
		return (NULL);
	l_val = ft_strlen((const char *)(*value)->value);
	len = width - l_val - ft_strlen((const char *)bonus);
	if (len <= 0)
		return (NULL);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (++i < len)
		str[i] = ' ';
	str[i] = '\0';
	return (str);
}

void	minus_width_case(char **bonus, t_value **value)
{
	int		flag;
	char	*str;

	if ((*value)->convs.info.flags.minus == true)
		flag = 1;
	else
		flag = 0;
	str = str_align(value, (*bonus));
	if (!str)
		return ;
	if (flag == 1)
		left_align(&str, &(*value));
	else
		right_align(&str, &(*bonus));
}
