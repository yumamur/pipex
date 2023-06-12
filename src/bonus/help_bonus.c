/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:49:09 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/30 19:49:10 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

int	pipex_help(int argc, char *av[])
{
	if (argc == 2 && (!ft_strcmp(av[1], "-h") || !ft_strcmp(av[1], "--help")))
	{
		ft_putstr("\nUsage:\n ./pipex <infile> <executable> (...) <executable");
		ft_putstr("> <outfile>\n ./pipex here_doc \"LIMITER\" <executable> (.");
		ft_putstr("..) <executable> <outfile>\n ./pipex -h | --help\n\nPipe g");
		ft_putstr("iven commands\n\nOptions:\n  -h, --help\t\tDisplays this m");
		ft_putstr("essage.\n\nArguments:\n  executable\t\tCan be both an alia");
		ft_putstr("s or a path to the executable.");
		exit(EXIT_SUCCESS);
	}
	return (0);
}
