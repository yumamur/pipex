#include "../include/pipex.h"

void	exec(char cmd[], char *envp[])
{
	char	**arg_cmd;

	arg_cmd = p_split(cmd, 32);
	if (execve(getpath(arg_cmd[0], envp), arg_cmd, envp) == -1)
	{
		write(2, "Could not execute command ", 26);
		handle_error(arg_cmd[0]);
	}
}

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

	fd = open(argv[4], O_CREAT | O_RDWR | O_TRUNC);
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
		handle_error("Error giving birth");
	if (pid == 0)
		child(argv, envp, fds);
	parent(argv, envp, fds);
	return (0);
}
