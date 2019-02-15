/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:45:35 by flhember          #+#    #+#             */
/*   Updated: 2019/02/15 13:07:30 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../Libft/includes/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef	struct		s_conv
{
	char			type;
	char			*(*f)(void *var, char *str);
	struct	s_conv	*next;
}					t_conv;

typedef struct		s_option
{
	int				min;
	int				prec;
	int				plus;
	int				minus;
	int				hash;
	int				space;
	int				zero;
	char			*size;
	char			*option;

}					t_option;

void		ft_creatlst(t_conv	**list);
char		**ft_set_tab(char *str, char **tab_final);
char		**ft_convert_param(char **tab, t_conv **list, va_list ap);
char		*ft_convert_c(void *var, char *str);
char		*ft_convert_s(void *var, char *str);
char		*ft_convert_p(void *var, char *str);
char		*ft_convert_i_d(void *var, char *str);
void		free_list(t_conv **list);
void		free_tab(char ***tab);
t_option	*ft_get_option(char *str);

#endif
