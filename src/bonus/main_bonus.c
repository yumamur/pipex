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

#include "../../include/pipex.h"

void	execute(char *cmd, char *envp[])
{
	char	**argcmd;

	argcmd = ft_split(cmd, 32);
	if (!access(argcmd[0], X_OK))
	{
		clear_path(argcmd);
		if (execve(get_path(argcmd[0], envp), argcmd, envp) == -1)
		{
			write(2, argcmd[0], ft_strlen(argcmd[0]));
			ft_freesplit(argcmd);
			handle_error("\1");
		}
	}
	else if (execve(get_path(argcmd[0], envp), argcmd, envp) == -1)
	{
		write(2, argcmd[0], ft_strlen(argcmd[0]));
		ft_freesplit(argcmd);
		handle_error("\1");
	}
	ft_freesplit(argcmd);
}

void	pipe_x(char *cmd, char *envp[])
{
	int	fds[2];
	int	pid;

	if (pipe(fds) == -1)
		handle_error("Error piping");
	pid = fork();
	if (pid == -1)
		handle_error("Error forking");
	if (!pid)
	{
		close(fds[0]);
		dup2(fds[1], STDOUT_FILENO);
		execute(cmd, envp);
	}
	else
	{
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	int	fds[2];
	int	c;

	if (argc < 5)
		handle_error("\5");
	if (!ft_strcmp(argv[1], "here_doc"))
	{
		if (argc < 6)
			handle_error("\6");
		fds[0] = open_fd(argv[argc - 1], O_CREAT | O_RDWR | O_APPEND, 0644);
		here_doc(argv);
		c = 2;
	}
	else
	{
		fds[0] = open_fd(argv[1], O_RDONLY, 0);
		fds[1] = open_fd(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
		dup2(fds[0], STDIN_FILENO);
		c = 1;
	}
	while (++c < argc - 2)
		pipe_x(argv[c], envp);
	dup2(fds[1], STDOUT_FILENO);
	execute(argv[argc - 2], envp);
	return (EXIT_SUCCESS);
}
