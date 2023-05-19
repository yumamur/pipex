/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:10:18 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/03 15:17:21 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	pipe_heredoc(char *argv[], const char *envp[])
{
	int	fds[2];
	int	pid;

	if (pipe(fds) == -1)
		handle_error("Error piping heredoc");
	pid = fork();
	if (pid == -1)
		handle_error("Error forking heredoc");
	if (!pid)
		heredoc(fds, argv, envp);
	else
	{
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		wait(NULL);
	}
}

void	pipe_cmd(char *cmd, const char *envp[])
{
	int	fds[2];
	int	pid;

	if (pipe(fds) == -1)
		handle_error("Could not pipe");
	pid = fork();
	if (pid == -1)
		handle_error("Could not fork");
	if (!pid)
	{
		close(fds[0]);
		dup2(fds[1], STDOUT_FILENO);
		exec(cmd, envp);
	}
	else
	{
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
	}
}

int	main(int argc, char *argv[], const char *envp[])
{
	int	fds[2];
	int	c;

	if (argc < 5)
		handle_error("\5");
	if (!ft_strcmp(argv[1], "here_doc"))
	{
		if (argc < 6)
			handle_error("\6");
		fds[1] = open_fd(argv[argc - 1], O_CREAT | O_RDWR | O_APPEND, 0644, 0);
		pipe_heredoc(argv, envp);
		c = 3;
	}
	else
	{
		fds[0] = open_fd(argv[1], O_RDONLY, 0, 0);
		fds[1] = open_fd(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644, 0);
		dup2(fds[0], STDIN_FILENO);
		c = 2;
	}
	while (c < argc - 2)
		pipe_cmd(argv[c++], envp);
	dup2(fds[1], STDOUT_FILENO);
	exec(argv[argc - 2], envp);
}
