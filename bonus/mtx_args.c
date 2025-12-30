#include "ft_printf.h"

void	free_mtx(char **mtx)
{
	int	i;

	i = -1;
	if (!mtx)
		return ;
	while (mtx[++i] != NULL)
		free(mtx[i]);
	free(mtx);
}

static int	find_end(const char *s, int start)
{
	int	i;
	int	per;
	int	space;
	int	len;

	len = 0;
	i = start;
	per = 0;
	space = 0;
	while (s[i] && (ft_strchr("-0.# +%", s[i]) || ft_isdigit(s[i])))
	{
		if (s[i] == '%')
			per++;
		else if (s[i] == ' ')
			space++;
		if (space > 1 || per > 1)
			break ;
		len++;
		i++;
	}
	len++;
	return (len);
}

static int	find_start(const char *s, int idx)
{
	int	i;
	int	count_per;

	i = -1;
	count_per = -1;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			count_per++;
			if (count_per == idx)
				return (i);
			if (s[i + 1] == '%')
				i++;
		}
	}
	return (i);
}

static char	*new_arg(const char *format, int idx)
{
	char	*arg;
	int		i;
	int		end;

	i = find_start(format, idx);
	end = find_end(format, i);
	arg = ft_substr(format, i, end);
	if (!arg)
		return (NULL);
	return (arg);
}

char	**mtx_args_init(const char *format, int size)
{
	char	**mtx;
	int		i;

	i = -1;
	mtx = NULL;
	mtx = malloc((size + 1) * sizeof(char *));
	if (!mtx)
		return (NULL);
	while (++i < size)
	{
		mtx[i] = new_arg(format, i);
		if (!mtx)
		{
			free_mtx(mtx);
			return (NULL);
		}
	}
	mtx[i] = NULL;
	return (mtx);
}
