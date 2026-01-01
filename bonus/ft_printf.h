#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_flags
{
	int		width;
	int		precision;
	bool	minus;
	bool	zero;
	bool	point;
	bool	hashtag;
	bool	space;
	bool	plus;
	bool	error;
}		t_flags;

typedef struct s_type
{
	bool	character;
	bool	string;
	bool	integer;
	bool	pointer;
	bool	hexadecimal;
	bool	hexadecimal_up;
	bool	uns_decimal;
	bool	percent;
	bool	no_type;
}		t_type;

typedef struct s_info
{
	bool	valid;
	bool	bonus;
	t_flags	flags;
	t_type	type;
}		t_info;

typedef struct s_convs
{
	t_info	info;
	char	conv;
}		t_convs;

typedef struct s_value
{
	void	*arg;
	char	*value;
	t_convs	convs;
}		t_value;

typedef struct s_data
{
	bool	print_flag;
	int		len;
	t_value	*values;
}		t_data;

typedef struct s_fun
{
	int		idx;
	char	*(*f)(t_value *value);
}		t_fun;

int		ft_printf(const char *format, ...);
t_data	*init_data(const char *format, va_list args);
t_info	info_init(void);
t_convs	convs_init(void);
t_value	*values_init(int len);
int		find_len_args(const char *format);
t_data	*data_setup(const char *format);
char	**mtx_args_init(const char *format, int size);
void	free_data(t_data **data);
void	free_mtx(char **mtx);
void	convs_setup(t_value *value, char *arg);
t_convs	convs_init(void);
t_value	*values_init(int len);
void	check_flag_comb(t_data **data);
void	transform_value(t_value **values, int len);
char	*ft_itoa_base(t_value *value);
char	*ft_pointer_itoa(t_value value);
void	precision_case(t_value *value);
void	shift_one_char(char **value);
void	zero_case(char **bonus, t_value *value);
void	space_plus_case(char **bonus, t_value *value);
void	hashtag_case(char **bonus, t_value *value);
void	minus_width_case(char **bonus, t_value **value);
int		check_valid_args(t_value *value, char *args);
int	value_len(t_value *value);

#endif
