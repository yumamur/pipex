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

# include "libft.h"
# include "shellft.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

int			open_fd(char *file, int flags, t_uint mode);
void		handle_error(char str[]);
const char	*get_path(char *cmd, char *envp[]);
void		exec(char cmd[], char *envp[]);

#endif
