#include "../include/pipex.h"

void	handle_error(char errmsg[])
{
	if (!errmsg)
		write(2, "Error: Invalid argument count", 29);
	else
		perror(errmsg);
	exit(1);
}

void	add_cmd(char *allpaths[], char *cmd)
{
	int	i;

	i = -1;
	while (allpaths[++i])
		allpaths[i] = strjoin(allpaths[i], cmd);
}

char	*getpath(char cmd[], char *envp[])
{
	char	**allpaths;
	char	*exec;
	int		i;

	allpaths = p_split(p_substr(envp, "PATH="), ':');
	add_cmd(allpaths, cmd);
	i = 0;
	while (access(allpaths[++i], F_OK))
		i++;
	exec = ft_strdup(allpaths[i]);
	i = -1;
	while (allpaths[++i])
		free(allpaths[i]);
	free(allpaths);
	return (exec);
}
