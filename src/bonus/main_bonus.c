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

void	exec(char *cmd, char *envp[], char **sub)
{
	char		**argcmd;
	t_c_char	*path;

	if (sub)
		argcmd = sub;
	else
		argcmd = ft_split(cmd, 32);
	if (!access(argcmd[0], X_OK))
	{
		path = ft_strdup(argcmd[0]);
		ft_free_change(argcmd[0], ft_file_name((argcmd[0])));
		if_exec(path, argcmd, envp);
	}
	else
	{
		path = get_path(argcmd[0], envp);
		if_exec(path, argcmd, envp);
	}
	ft_free_2pt(argcmd);
	free((void *)path);
}

void	pipe_heredoc(char *argv[], char *envp[], t_uint cmd_ct)
{
	int	fds[2];
	int	pid;

	if (pipe(fds) == -1)
		handle_error("Error piping heredoc", 0);
	pid = fork();
	if (pid == -1)
		handle_error("Error forking heredoc", 0);
	if (!pid)
		heredoc(fds, argv, envp, cmd_ct);
	else
	{
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		wait(NULL);
	}
}

void	pipe_cmd(char *cmd, char *envp[])
{
	int	fds[2];
	int	pid;

	if (pipe(fds) == -1)
		handle_error("Could not pipe", 0);
	pid = fork();
	if (pid == -1)
		handle_error("Could not fork", 0);
	if (!pid)
	{
		close(fds[0]);
		dup2(fds[1], STDOUT_FILENO);
		exec(cmd, envp, NULL);
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
		handle_error("\5", -1);
	if (!ft_strcmp(argv[1], "here_doc"))
	{
		if (argc < 6)
			handle_error("\6", 0);
		fds[1] = open_fd(argv[argc - 1], O_CREAT | O_RDWR | O_APPEND, 0644, 0);
		pipe_heredoc(argv, envp, argc - 4);
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
	exec(argv[argc - 2], envp, NULL);
}
