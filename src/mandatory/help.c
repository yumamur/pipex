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

#include "../../include/pipex.h"

int	pipex_help(void)
{
	ft_putstr("\nUsage:\n ./pipex <file> <executable> <executable> <file>\n .");
	ft_putstr("/pipex -h | --help\n\nMimic the behaviour of the \"< file cmd ");
	ft_putstr("| cmd > file\" command line\n\nOptions:\n  -h, --help\t\tDispl");
	ft_putstr("ays this message.\n\nArguments:\n  executable\t\tCan be both a");
	ft_putstr("n alias or a path to the executable.");
	return (0);
}
