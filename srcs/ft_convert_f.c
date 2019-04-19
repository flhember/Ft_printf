/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:28:23 by flhember          #+#    #+#             */
/*   Updated: 2019/04/12 17:58:30 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_filling(char *str, char *var, t_option **list)
{
	size_t		size_var;

	size_var = ft_strlen(var);
	if (var[0] == '-')
		size_var--;
	if ((*list)->minus && ((*list)->zero || ((*list)->prec > (int)size_var)))
		str = ft_put_zero_minus(str, var, list);
	if (!(*list)->minus && ((*list)->zero || ((*list)->prec > (int)size_var)))
		str = ft_put_zero(str, var, list);
	str = ft_put_signe(str, var, list, size_var);
	str = ft_put_num(str, var, list, size_var);
	return (str);
}

static size_t	ft_find_good_size2(char *var, t_option **list, size_t size)
{
	size_t		i;

	i = 0;
	if ((*list)->prec > (int)(*list)->min &&
			(*list)->prec >= (int)ft_strlen(var))
	{
		size = (*list)->prec;
		if (var[0] == '-' || (var[0] == '-' && ((*list)->minus ||
						(*list)->space || (*list)->zero || (*list)->plus)))
			size++;
	}
	else
		size = ft_strlen(var);
	if ((var[0] != '-' && ((*list)->space || ((*list)->plus))))
		size++;
	return (size);
}

static size_t	ft_find_good_size(char *var, t_option **list, size_t size)
{
	size_t	i;

	i = 0;
	if ((*list)->prec == -1)
		(*list)->prec++;
	if ((int)(*list)->min >= (*list)->prec && (*list)->min > ft_strlen(var))
	{
		size = (*list)->min;
		if (var[0] == '-' && (int)(*list)->min == (*list)->prec)
			size += 1;
		return (size);
	}
	else
		size = ft_find_good_size2(var, list, size);
	return (size);
}

char			*ft_good_var(va_list ap, t_option **list)
{
	char	*str;

	str = NULL;
	if (!((*list)->size) || (*list)->size[0] == 'l')
	{
		if ((*list)->prec == 0)
			str = ft_ftoa_64(va_arg(ap, double), 6, (*list)->hash);
		else if ((*list)->prec == -1)
			str = ft_ftoa_64(va_arg(ap, double), 0, (*list)->hash);
		else
			str = ft_ftoa_64(va_arg(ap, double), (*list)->prec, (*list)->hash);
	}
	else if ((*list)->size[0] == 'L')
	{
		if ((*list)->prec == 0)
			str = ft_ftoa_80(va_arg(ap, long double), 6, (*list)->hash);
		else if ((*list)->prec == -1)
			str = ft_ftoa_80(va_arg(ap, long double), 0, (*list)->hash);
		else
			str = ft_ftoa_80(va_arg(ap, long double), (*list)->prec, (*list)->hash);
	}
	return (str);
}

static char		*ft_check_spec(char *str_final, char *var, t_option **list)
{
	int 		size_var;
	int			i;

	i = -1;
	size_var = ft_strlen(var);
	if (var[size_var - 1] != '.' && (var[size_var - 1] > '9' || var[size_var - 1] < '0'))
	{
		if ((*list)->min > (size_t)size_var)
			str_final = ft_strnewspace((*list)->min);
		else
			str_final = ft_strnewspace(size_var);
	}
	if (str_final)
	{
		if ((*list)->minus)
			while (i++ < size_var - 1)
				str_final[i] = var[i];
		else
		{
			i = ft_strlen(str_final);
			while (size_var >= 0)
				str_final[i--] = var[size_var--];
		}
	}
	return (str_final);
}

char			*ft_convert_f(va_list ap, char *str)
{
	t_option	*list;
	char		*var;
	size_t		size;
	char		*str_final;

	size = 0;
	list = NULL;
	str_final = NULL;
	list = ft_get_option(str);
	if (str[1] == 'f')
	{
		ft_free_option(&list);
		ft_strdel(&str);
		str = ft_ftoa_64(va_arg(ap, double), 6, 0);
		return (str);
	}
	var = ft_good_var(ap, &list);
	if ((str_final = ft_check_spec(str_final, var, &list)) != NULL)
		return (str_final);
	size = ft_find_good_size(var, &list, size);
	str_final = ft_strnewspace(size);
	str_final = ft_filling(str_final, var, &list);
	ft_free_option(&list);
	ft_strdel(&str);
	ft_strdel(&var);
	return (str_final);
}
