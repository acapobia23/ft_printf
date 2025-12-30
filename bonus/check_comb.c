#include "ft_printf.h"

static int	count_flags(t_convs *convs)
{
	int	counter;

	counter = 0;
	if (convs->info.flags.minus == true)
		counter++;
	if (convs->info.flags.zero == true)
		counter++;
	if (convs->info.flags.point == true)
		counter++;
	if (convs->info.flags.hashtag == true)
		counter++;
	if (convs->info.flags.space == true)
		counter++;
	if (convs->info.flags.plus == true)
		counter++;
	if (convs->info.flags.width != -1 && (convs->info.flags.point == false
			&& convs->info.flags.zero == false))
		counter++;
	return (counter);
}

static void	check_flags_comb(t_convs *convs)
{
	if (convs->info.flags.point == true || convs->info.flags.minus == true)
	{
		if (convs->info.flags.zero == true)
			convs->info.flags.zero = false;
	}
	if (convs->info.flags.plus == true && convs->info.flags.space == true)
		convs->info.flags.space = false;
}

static void	check_conv_comb(t_convs *convs)
{
	char	c;

	c = convs->conv;
	if (convs->info.flags.zero == true && (c == 'c'))
		convs->info.flags.zero = false;
	if (convs->info.flags.point == true && (c == 'p' || c == 'c'))
		convs->info.flags.point = false;
	if (convs->info.flags.hashtag == true && (c != 'x' && c != 'X'))
		convs->info.flags.hashtag = false;
	if (convs->info.flags.space == true && (c != 'd' && c != 'i'))
		convs->info.flags.space = false;
	if (convs->info.flags.plus == true && (c != 'd' && c != 'i'))
		convs->info.flags.plus = false;
	if (count_flags(convs) == 0)
		convs->info.bonus = false;
}

void	check_flag_comb(t_data **data)
{
	int	i;

	i = -1;
	while (++i < (*data)->len)
	{
		if ((*data)->values[i].convs.info.bonus == true)
			check_conv_comb(&((*data)->values[i].convs));
		if ((*data)->values[i].convs.info.bonus == true)
			check_flags_comb(&((*data)->values[i].convs));
	}
}
