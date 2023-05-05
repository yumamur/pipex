/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:10:28 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/03 15:17:34 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

int	open_fd(char *file, int flags, unsigned int mode)
{
	int	ret;

	ret = open((const char *)file, flags, mode);
	if (ret == -1)
	{
		write(2, "Could not open file ", 20);
		handle_error(file);
	}
	return (ret);
}

void	clear_path(char **argcmd)
{
	char	*tmp;

	tmp = ft_strdup(ft_strrchr(argcmd[0], '/') + 1);
	free(argcmd[0]);
	argcmd[0] = ft_strdup(tmp);
	free(tmp);
}

void	handle_error(char errmsg[])
{
	if (errmsg[0] == 5)
		write(2, "Insufficent argument. Required: \033[31;1m4\033[m", 46);
	else if (errmsg[0] == 6)
	{
		write(2, "Insufficent argument for 'here_doc'.", 36);
		write(2, "Required: \033[31;1m5\033[m", 21);
	}
	else if (errmsg[0] == 1)
		write(2, ": command not found\n", 20);
	else
		perror(errmsg);
	exit(127);
}

static void	add_cmd(char *allpaths[], char *cmd)
{
	char	*tmp1;
	char	*tmp2;

	while (*allpaths)
	{
		tmp1 = ft_strjoin(*(const char **)allpaths, "/");
		tmp2 = ft_strjoin((const char *)tmp1, (const char *)cmd);
		free(tmp1);
		free(*allpaths);
		*allpaths = tmp2;
		tmp2 = NULL;
		allpaths++;
	}
}

const char	*get_path(char *cmd, char *envp[])
{
	char	**allpaths;
	char	*ret;
	int		i;

	allpaths = ft_split(ft_getenv((const char **)envp, "PATH"), ':');
	i = 0;
	add_cmd(allpaths, cmd);
	while (allpaths[i])
	{
		if (!access((const char *)(allpaths[i]), F_OK))
		{
			ret = ft_strdup(allpaths[i]);
			ft_freesplit(allpaths);
			return ((const char *)ret);
		}
		i++;
	}
	return (NULL);
}
