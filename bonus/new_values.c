#include "ft_printf.h"

char	*ft_pointer_itoa(t_value value)
{
	char	*tmp;
	char	*res;

	if (value.arg == NULL)
		return (ft_strdup("(nil)"));
	tmp = ft_itoa_base(&value);
	res = ft_strjoin("0x", (const char *)tmp);
	free(tmp);
	return (res);
}

static void	add_bonus(t_value **value, const char *bonus)
{
	char	*tmp;

	if (!bonus)
		return ;
	tmp = ft_strjoin(bonus, (const char *)((*value)->value));
	if (!tmp)
		return ;
	free((*value)->value);
	(*value)->value = tmp;
}

static void	make_bonus(t_value *value)
{
	char	*bonus;
	t_flags	*ptr;

	bonus = NULL;
	ptr = &(value->convs.info.flags);
	if (ptr->point == true)
		precision_case(&(*value));
	if (ptr->zero == true)
		zero_case(&bonus, &(*value));
	if (ptr->space == true || ptr->plus == true)
		space_plus_case(&bonus, value);
	if (ptr->hashtag == true)
		hashtag_case(&bonus, value);
	if (ptr->minus == true && ptr->zero == false)
		minus_width_case(&bonus, &value);
	if (ptr->width >= 0 && (ptr->minus == false && ptr->zero == false))
		minus_width_case(&bonus, &value);
	add_bonus(&value, (const char *)bonus);
	if (bonus)
		free(bonus);
}

static char	*copy_value(void *arg)
{
	char	*str;

	str = ft_strdup((const char *)arg);
	if (!str)
		return (NULL);
	return (str);
}

void	transform_value(t_value **values, int len)
{
	int		i;
	char	c;

	i = -1;
	while (++i < len)
	{
		if ((*values)[i].convs.info.valid == true)
		{
			c = (*values)[i].convs.conv;
			if (c == 'c' || c == 's' || c == '%')
			{
				if (!(*values)[i].arg)
					(*values)[i].value = ft_strdup("(null)");
				else
					(*values)[i].value = copy_value((*values)[i].arg);
			}
			else if (c == 'p')
				(*values)[i].value = ft_pointer_itoa((*values)[i]);
			else
				(*values)[i].value = ft_itoa_base(&(*values)[i]);
			if ((*values)[i].convs.info.bonus == true)
				make_bonus(&(*values)[i]);
		}
	}
}
