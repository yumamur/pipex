/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:10:28 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/06 00:04:04 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	exec(char cmd[], char *envp[])
{
	char	**argcmd;

	argcmd = ft_split(cmd, 32);
	if (!access(argcmd[0], X_OK))
	{
		ft_free_change(argcmd[0], ft_file_name((argcmd[0])));
		if (execve(get_path(argcmd[0], envp), argcmd, envp) == -1)
		{
			write(2, argcmd[0], ft_strlen(argcmd[0]));
			write(2, ": command not found\n", 20);
			ft_free_2pt(argcmd);
			handle_error("\1");
		}
	}
	else if (execve(get_path(argcmd[0], envp), argcmd, envp) == -1)
	{
		write(2, argcmd[0], ft_strlen(argcmd[0]));
		write(2, ": command not found\n", 20);
		ft_free_2pt(argcmd);
		handle_error("\1");
	}
	ft_free_2pt(argcmd);
}

void	handle_error(char errmsg[])
{
	if (!errmsg)
		write(2, "Error: Invalid argument count", 29);
	else if (errmsg[0] == 1)
		;
	else
		perror(errmsg);
	exit(127);
}

void	add_cmd(char *allpaths[], char *cmd)
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
			ft_free_2pt(allpaths);
			return ((const char *)ret);
		}
		i++;
	}
	return (NULL);
}
