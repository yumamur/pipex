/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:10:18 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/06 00:03:52 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	child(char *argv[], char *envp[], int fds[])
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		handle_error("Invalid infile");
	dup2(fd, 0);
	dup2(fds[1], 1);
	close(fds[0]);
	exec(argv[2], envp);
}

void	parent(char *argv[], char *envp[], int fds[])
{
	int	fd;

	fd = open(argv[4], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (fd < 0)
		handle_error("Invalid outfile");
	dup2(fd, 1);
	dup2(fds[0], 0);
	close(fds[1]);
	exec(argv[3], envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fds[2];
	pid_t	pid;

	if (argc != 5)
		handle_error(NULL);
	if (pipe(fds) == -1)
		handle_error("Error piping");
	pid = fork();
	if (pid == -1)
		handle_error("Error forking");
	if (pid == 0)
		child(argv, envp, fds);
	parent(argv, envp, fds);
	return (0);
}
