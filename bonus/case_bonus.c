#include "ft_printf.h"

static void	add_hashtag(char **bonus, char c)
{
	char	*tmp;

	tmp = NULL;
	if (c == 'x')
		tmp = ft_strjoin("ox", (const char *)(*bonus));
	else
		tmp = ft_strjoin("oX", (const char *)(*bonus));
	if (!tmp)
		return ;
	free((*bonus));
	(*bonus) = NULL;
	(*bonus) = tmp;
}

void	hashtag_case(char **bonus, t_value *value)
{
	char	c;

	c = value->convs.conv;
	if (value->convs.info.flags.precision == 0)
		return ;
	if (ft_strlen((const char *)value->value) == 1
			&& value->value[0] == '0')
		return ;
	if (!(*bonus))
	{
		if (c == 'x')
			(*bonus) = ft_strdup("0x");
		else
			(*bonus) = ft_strdup("0X");
		return ;
	}
	if (c == 'x')
		add_hashtag(&(*bonus), 'x');
	else
		add_hashtag(&(*bonus), 'X');
}

void	space_plus_case(char **bonus, t_value *value)
{
	char	c;

	if (value->value[0] == '-')
		return ;
	if (value->convs.info.flags.space == true)
		c = ' ';
	else
		c = '+';
	if (!(*bonus))
	{
		(*bonus) = ft_strdup((const char *)&c);
		return ;
	}
	(*bonus)[0] = c;
}

static char	*bonus_init(int len)
{
	char	*bonus;
	int		i;

	i = -1;
	bonus = NULL;
	bonus = malloc((len + 1) * sizeof(char));
	if (!bonus)
		return (NULL);
	while (++i < len)
		bonus[i] = '0';
	bonus[i] = '\0';
	return (bonus);
}

void	zero_case(char **bonus, t_value *value)
{
	int	pre;
	int	l_value;
	int	len;

	pre = value->convs.info.flags.width;
	l_value = value_len(value);
	if (pre == 0)
		return ;
	else if (pre - l_value <= 0)
		return ;
	if ((value->convs.conv == 'i' || value->convs.conv == 'd')
		&& value->value[0] == '-')
		l_value -= 1;
	len = pre - l_value;
	(*bonus) = bonus_init(len);
	if (!(*bonus))
		return ;
	if ((value->convs.conv == 'i' || value->convs.conv == 'd')
		&& value->value[0] == '-')
	{
		shift_one_char(&(value->value));
		(*bonus)[0] = '-';
	}
}
