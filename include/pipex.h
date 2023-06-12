/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:10:05 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/03 16:57:28 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/shellft.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>

int			pipex_help(void);
int			open_fd(char *file, int flags, t_uint mode);
void		handle_error(char str[]);
t_c_char	*get_path(char *cmd, char *envp[]);
void		if_exec(t_c_char *path, char **argcmd, char **envp);

#endif
