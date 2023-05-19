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

#include "../../include/pipex_bonus.h"

void	exec(char *cmd, const char *envp[])
{
	char		**argcmd;
	char *const	*pt;

	argcmd = ft_split(cmd, 32);
	pt = (char **)envp;
	if (!access(argcmd[0], X_OK))
	{
		ft_free_change(argcmd[0], ft_file_name((argcmd[0])));
		if (execve(get_path(argcmd[0], envp), argcmd, pt) == -1)
		{
			write(2, argcmd[0], ft_strlen(argcmd[0]));
			ft_free_2pt(argcmd);
			handle_error("\1");
		}
	}
	else if (execve(get_path(argcmd[0], envp), argcmd, pt) == -1)
	{
		write(2, argcmd[0], ft_strlen(argcmd[0]));
		ft_free_2pt(argcmd);
		handle_error("\1");
	}
	ft_free_2pt(argcmd);
}

int	open_fd(char *file, int flags, unsigned int mode, int offset)
{
	int		ret;
	char	buf[1];

	ret = open((const char *)file, flags, mode);
	if (ret == -1)
	{
		write(2, "Could not open file ", 20);
		handle_error(file);
	}
	if (offset)
	{
		if (offset > 0)
			while (offset--)
				write(ret, "\0", 1);
		else
		{
			offset *= -1;
			while (offset--)
				read(ret, buf, 1);
		}
	}
	return (ret);
}

void	handle_error(char errmsg[])
{
	if (errmsg[0] == 5)
		write(2, "Insufficent argument. Required: \033[31;1m4\033[m", 44);
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

static void	add_cmd(const char *allpaths[], char *cmd)
{
	const char	*tmp1;
	const char	*tmp2;

	while (*allpaths)
	{
		tmp1 = ft_strjoin(*allpaths, "/");
		tmp2 = ft_strjoin(tmp1, (const char *)cmd);
		free((void *)tmp1);
		free(*(void **)allpaths);
		*allpaths = (char *)tmp2;
		tmp2 = NULL;
		allpaths++;
	}
}

const char	*get_path(char *cmd, const char *envp[])
{
	const char	**allpaths;
	const char	*ret;
	int			i;

	allpaths = (const char **)ft_split(ft_getenv(envp, "PATH"), ':');
	i = 0;
	add_cmd(allpaths, cmd);
	while (allpaths[i])
	{
		if (!access((const char *)(allpaths[i]), F_OK))
		{
			ret = (const char *)ft_strdup(allpaths[i]);
			ft_free_2pt((char **)allpaths);
			return (ret);
		}
		i++;
	}
	return (NULL);
}
