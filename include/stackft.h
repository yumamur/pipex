/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:21:42 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/14 15:21:48 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKFT_H
# define STACKFT_H

# include "memft.h"
# include <unistd.h>

# ifndef _STRUCT_STACK
#  define _STRUCT_STACK

typedef struct s_stack
{
	const char				*data;
	const unsigned int		size;
	const unsigned int		cap;
	const unsigned long int	index;
	const unsigned long		_type;
}	t_stack;
# endif /* _STRUCT_STACK */

/* It is recommended to set _type parameter using 'sizeof()' macro.
 * */
void	ft_stack_init(t_stack *pt, unsigned int cap, unsigned long _type);
void	ft_stack_xpanda(t_stack *pt_stack, unsigned int n);
void	ft_stack_push(t_stack *pt_stack, void *val);
void	*ft_stack_pop(t_stack *pt_stack);
void	ft_stack_clear(t_stack *pt_stack);

#endif
