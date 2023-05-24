/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:12:12 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/08 18:12:14 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

static void	heredoc_out(int fds[])
{
	t_ulint	i;
	int		hd_fd;	
	char	str[100];

	hd_fd = open_fd(".tmpfile", O_RDONLY, 0644, 0);
	if (hd_fd == -1)
		handle_error("Could not open heredoc file");
	ft_memset(str, 0, 100);
	while (1)
	{
		i = read(hd_fd, str, 100);
		if (i > 0)
			write(fds[1], str, ft_strlen(str));
		else if (!i)
			break ;
		else if (i < 0)
		{
			unlink(".tmpfile");
			handle_error("heredoc output error");
		}
	}
	close(hd_fd);
	unlink(".tmpfile");
}

void	heredoc(int fds[], char *argv[], char *envp[])
{
	int		hd_fd;
	char	*str;

	close(fds[0]);
	hd_fd = open_fd(".tmpfile", O_CREAT | O_RDWR | O_TRUNC, 0644, 0);
	while (1)
	{
		str = get_next_line(0);
		if (!ft_strncmp(str, argv[2], ft_strlen(argv[2])))
		{
			ft_free_pt(str);
			str = NULL;
			close(hd_fd);
			heredoc_exec(envp);
			heredoc_out(fds);
		}
		write(hd_fd, str, ft_strlen(str));
		if (str)
			ft_free_pt(str);
	}
}
