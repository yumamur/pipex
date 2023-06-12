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
	t_c_char	*data;
	t_c_uint	size;
	t_c_uint	cap;
	t_c_ulint	index;
	t_c_ulong	_type;
}	t_stack;
# endif /* _STRUCT_STACK */

/* It is recommended to set _type parameter using the macro 'sizeof()'.
 * */
void	ft_stack_init(t_stack *pt, t_uint cap, t_ulong _type);
void	ft_stack_xpanda(t_stack *pt_stack, t_uint n);
void	ft_stack_push(t_stack *pt_stack, void *val);
void	*ft_stack_pop(t_stack *pt_stack);
void	ft_stack_clear(t_stack *pt_stack);
void	ft_stack_shift_up(t_stack *stack);
void	ft_stack_nshift_up(t_stack *stack, t_uint n);
void	ft_stack_shift_down(t_stack *stack);
void	ft_stack_nshift_down(t_stack *stack, t_uint n);
#endif /* STACKFT_H */
