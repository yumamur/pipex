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

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif

# include "shellft.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>

void		exec(char cmd[], char *envp[], char **sub);
void		if_exec(t_c_char *path, char **argcmd, char **envp);
int			open_fd(char *file, int flags, t_uint mode, int offset);
void		handle_error(char str[], t_uint mode);
t_c_char	*get_path(char *cmd, char *envp[]);

void		heredoc(int fds[], char *argv[], char *envp[], t_uint cmd_ct);
void		heredoc_exec(char *envp[]);
char		*get_next_line(int fd);

#endif
