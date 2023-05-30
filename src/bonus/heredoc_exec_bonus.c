/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:12:24 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/08 18:12:25 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

static int	exec_cmdsub(t_c_char *buf, char *envp[])
{
	char	*sub[32];
	int		pid;
	size_t	len;

	pid = fork();
	if (pid == -1)
		handle_error("Could not fork", 0);
	sub[2] = (char *)ft_shell_cmdsub(buf);
	if (!pid)
	{
		sub[0] = ft_strdup("sh");
		sub[1] = ft_strdup("-c");
		ft_free_change((void **)&sub[2], ft_strtrim(sub[2], "$()"));
		sub[2] = ft_strjoin_frees2("command ", sub[2]);
		sub[3] = NULL;
		exec(NULL, envp, sub);
	}
	else
	{
		len = ft_strlen(sub[2]);
		free(sub[2]);
		waitpid(pid, NULL, 0);
		return (len);
	}
	return (0);
}

static void	heredoc_parse(t_c_char *buf, int f_size, char *envp[])
{
	int		i;
	int		fd;

	fd = open_fd(".tmpfile", O_RDWR | O_TRUNC | O_CREAT, 0644, 0);
	dup2(fd, STDOUT_FILENO);
	i = 0;
	while (i < f_size)
	{
		if (buf[i] == '$' && buf[i + 1] != '(')
			i += ft_shell_var(fd, &(buf[i]), (t_c_char **)envp);
		else if (buf[i] == '$' && buf[i + 1] == '(')
			i += exec_cmdsub(buf, envp);
		else
			write(fd, &(buf[i++]), 1);
	}
	close(fd);
}

void	heredoc_exec(char *envp[])
{
	int		fd;
	char	*buf;
	char	size[100];
	int		f_size;
	int		tmp;

	fd = open_fd(".tmpfile", O_RDWR, 0, 0);
	f_size = 0;
	while (1)
	{
		tmp = read(fd, size, 100);
		if (tmp > 0)
			f_size += tmp;
		else
			break ;
	}
	buf = malloc(f_size);
	close(fd);
	fd = open_fd(".tmpfile", O_RDWR, 0, 0);
	read(fd, buf, f_size);
	unlink(".tmpfile");
	buf[f_size] = '\0';
	heredoc_parse(buf, f_size, envp);
}
