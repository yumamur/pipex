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

void	handle_error(char errmsg[])
{
	if (errmsg[0] == 5)
		write(2, "Insufficent argument. See \"./pipex -h\"", 38);
	else if (errmsg[0] == 1)
		write(2, ": command not found\n", 20);
	else
		perror(errmsg);
	exit(127);
}

void	add_cmd(char *allpaths[], char *cmd)
{
	while (*allpaths)
	{
		*allpaths = ft_strjoin_frees1(*allpaths, "/");
		*allpaths = ft_strjoin_frees1(*allpaths, (t_c_char *)cmd);
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
	ft_free_2pt(allpaths);
	return (NULL);
}
