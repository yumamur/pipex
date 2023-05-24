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

void	if_exec(t_c_char *path, char **argcmd, char **envp)
{
	if (execve(path, argcmd, envp) == -1)
	{
		write(2, argcmd[0], ft_strlen(argcmd[0]));
		ft_free_2pt(argcmd);
		free((void *)path);
		handle_error("\1");
	}
}

void	exec(char *cmd, char *envp[])
{
	char		**argcmd;
	t_c_char	*path;

	argcmd = ft_split(cmd, 32);
	if (!argcmd)
		return ;
	path = get_path(argcmd[0], envp);
	if (!access(argcmd[0], X_OK))
	{
		ft_free_change(argcmd[0], ft_file_name((argcmd[0])));
		if_exec(path, argcmd, envp);
	}
	else
		if_exec(path, argcmd, envp);
	ft_free_2pt(argcmd);
	free((void *)path);
}

void	handle_error(char errmsg[])
{
	if (errmsg[0] == 5)
		write(2, "Insufficent argument. Required: \033[31;1m4\033[m", 44);
	else if (errmsg[0] == 1)
		write(2, ": command not found\n", 20);
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
		tmp1 = ft_strjoin(*(t_c_char **)allpaths, "/");
		tmp2 = ft_strjoin((t_c_char *)tmp1, (t_c_char *)cmd);
		free(tmp1);
		free(*allpaths);
		*allpaths = tmp2;
		tmp2 = NULL;
		allpaths++;
	}
}

t_c_char	*get_path(char *cmd, char *envp[])
{
	char	**allpaths;
	char	*ret;
	int		i;

	allpaths = ft_split(ft_getenv((t_c_char **)envp, "PATH"), ':');
	i = 0;
	add_cmd(allpaths, cmd);
	while (allpaths[i])
	{
		if (!access((t_c_char *)(allpaths[i]), F_OK))
		{
			ret = ft_strdup(allpaths[i]);
			ft_free_2pt(allpaths);
			return ((t_c_char *)ret);
		}
		i++;
	}
	return (NULL);
}
