/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackft_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:22:06 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/14 15:22:07 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKFT_INTERNAL_H
# define STACKFT_INTERNAL_H

# include "typeft.h"

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
# endif

void	_update_index(t_stack *pt_stack);
void	_stack_delone(t_stack *pt_stack);
void	_stack_settype(t_stack *pt_stack, t_ulong _type);
void	_stack_setcap(t_stack *pt_stack, t_uint cap);
void	_stack_setsize(t_stack *pt_stack, t_uint size);
#endif
