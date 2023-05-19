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

static void	heredoc_parse(const char *buf, int f_size, const char *envp[])
{
	int	i;
	int	fd;

	fd = open_fd(".tmpfile", O_RDWR | O_TRUNC, 0, 0);
	i = 0;
	while (i < f_size)
		if (buf[i] == '$' && buf[i + 1] != '(')
			i += ft_shell_var(fd, &(buf[i]), envp);
	else if (buf[i] == '$' && buf[i + 1] == '(')
		i += ft_shell_cmdsub(fd, &(buf[i + 1]), envp) + 1;
	else
		write(fd, &(buf[i++]), 1);
}

void	pipe_main(int argc, char *argv[], const char *envp[])
{
	int	fds[2];
	int	pid;

	if (pipe(fds) == -1)
		handle_error("Could not pipe");
	pid = fork();
	if (pid == -1)
		handle_error("Could not fork");
	if (!pid)
		main(argc, argv, envp);
	else
		wait(NULL);
}

static int	filesize(const char *envp[])
{
	char	buf[13];
	char	**arg;
	int		fd;

	arg = malloc(45);
	arg[0] = ft_strdup("void");
	arg[1] = ft_strdup(".tmpfile");
	arg[2] = ft_strdup("du -b .tmpfile");
	arg[3] = ft_strdup("cut -f1");
	arg[4] = ft_strdup(".tmpfilesize");
	arg[5] = NULL;
	pipe_main(5, arg, envp);
	ft_free_2pt(arg);
	fd = open_fd(".tmpfilesize", O_RDONLY, 0, 0);
	read(fd, buf, 13);
	close(fd);
	unlink(".tmpfilesize");
	fd = ft_atoi(buf);
	return (fd);
}

void	heredoc_exec(const char *envp[])
{
	int		fd;
	char	*buf;
	int		f_size;

	fd = open_fd(".tmpfile", O_RDWR, 0, 0);
	f_size = filesize(envp);
	buf = malloc(f_size);
	read(fd, buf, f_size);
	close(fd);
	buf[f_size] = '\0';
	heredoc_parse(buf, f_size, envp);
}
