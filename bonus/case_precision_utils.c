#include "ft_printf.h"

void	shift_one_char(char **value)
{
	char	*tmp;
	int		len;
	int		i;
	int		j;

	len = ft_strlen((const char *)(*value)) - 1;
	i = -1;
	j = 0;
	tmp = NULL;
	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return ;
	while (++i < len && (*value)[++j])
		tmp[i] = (*value)[j];
	tmp[i] = '\0';
	free((*value));
	(*value) = NULL;
	(*value) = ft_strdup(tmp);
	free(tmp);
}
