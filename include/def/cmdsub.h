/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdsub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:49:42 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/21 22:49:43 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMDSUB_H
# define CMDSUB_H

# define UNMATCHED_QT 1
# define UNFINISHED_SUB 2

# include "../libft.h"

# ifndef SHELLFT_STRUCTS
#  define SHELLFT_STRUCTS

typedef struct s_quote
{
	t_c_char	*bgn;
	t_c_char	*end;
}	t_quote;

typedef struct s_cmdsub
{
	t_c_char		*bgn;
	t_c_char		*end;
	t_c_char		*pt_err;
	int				errno;
	struct s_quote	qt;
	struct s_cmdsub	*next;
}	t_cmdsub;
# endif

char	*__set_return(t_cmdsub **cmd);
int		__set_errno(t_cmdsub *cmd, int num);
int		__cmdsub_init(t_cmdsub **pt, t_c_char *buf);

#endif
