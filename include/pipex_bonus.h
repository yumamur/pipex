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

int			main(int argc, char *argv[], const char *envp[]);
void		pipe_main(int argc, char *argv[], const char *envp[]);
void		exec(char cmd[], const char *envp[]);
int			open_fd(char *file, int flags, unsigned int mode, int offset);
void		handle_error(char str[]);
const char	*get_path(char *cmd, const char *envp[]);

void		heredoc(int fds[], char *argv[], const char *envp[]);
void		heredoc_exec(const char *envp[]);
char		*get_next_line(int fd);

#endif
