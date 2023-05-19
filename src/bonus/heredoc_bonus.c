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

/*static void	heredoc_out(int hd_fd, int fds[], char **str)
{
	ssize_t	i;

	while (1)
	{
		i = read(hd_fd, *str, 100);
		if (i > 0)
		{
			write(fds[1], *str, ft_strlen(*str));
			free(*str);
		}
		else if (!i)
		{
			free(*str);
			break ;
		}
		else if (i < 0)
		{
			free(*str);
			unlink(".heredoc_txt");
			handle_error("heredoc output error");
		}
	}
}
*/
void	heredoc(int fds[], char *argv[], const char *envp[])
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
			close(hd_fd);
			heredoc_exec(envp);
			exit(0);
		}
		write(hd_fd, str, ft_strlen(str));
		ft_free_pt(str);
	}
}
