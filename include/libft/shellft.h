/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:00:25 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/20 18:21:42 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELLFT_H
# define SHELLFT_H

# include "libft.h"

char		*ft_file_name(char *path);
t_c_char	*ft_getenv(t_c_char *envp[], t_c_char *name);
ssize_t		ft_envvar_namelen(t_c_char *pt);
int			ft_shell_var(int fd, t_c_char *buf, t_c_char *envp[]);
char		*ft_shell_cmdsub(t_c_char *buf);

#endif /* SHELLFT_H */
