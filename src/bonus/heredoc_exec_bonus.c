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

static void	heredoc_parse(t_c_char *buf, int f_size, char *envp[])
{
	int		i;
	int		fd;
	char	**sub;

	fd = open_fd(".tmpfile", O_RDWR | O_TRUNC, 0, 0);
	dup2(fd, STDOUT_FILENO);
	i = 0;
	sub = malloc(32);
	sub[0] = ft_strdup("sh");
	sub[1] = ft_strdup("-c");
	sub[2] = ft_strdup("echo ");
	sub[3] = NULL;
	while (i < f_size)
		if (buf[i] == '$' && buf[i + 1] != '(')
			i += ft_shell_var(fd, &(buf[i]), (t_c_char **)envp);
	else if (buf[i] == '$' && buf[i + 1] == '(')
	{
		sub[2] = ft_strjoin_to_s1(sub[2], (char *)ft_shell_cmdsub(&(buf[i])));
		exec(NULL, envp, sub);
		i += ft_strlen(sub[3]);
		free((void *)sub);
	}
	else
		write(fd, &(buf[i++]), 1);
}

void	pipe_main(int argc, char *argv[], char *envp[])
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

static int	filesize(char *envp[])
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

void	heredoc_exec(char *envp[])
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
