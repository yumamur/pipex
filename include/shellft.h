/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellparseft.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:00:25 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/19 16:00:27 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELLFT_H
# define SHELLFT_H

# include "libft.h"

typedef struct	s_quote
{
	const char		*start;
	const char		*end;
	const char		*text;
	struct s_quote	*next;
}	t_quote;

char		*ft_file_name(char *path);
const char	*ft_getenv(const char *envp[], const char *name);
ssize_t		ft_envvar_namelen(const char *pt);
int			ft_shell_var(int fd, const char *buf, const char *envp[]);
int			ft_shell_cmdsub(int fd, const char *buf, const char *envp[]);
#endif
