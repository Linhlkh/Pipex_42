/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:18:04 by khle              #+#    #+#             */
/*   Updated: 2023/03/06 06:09:56 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

void	ac_error(void)
{
	write(2, "./pipex infile cmd1 cmd2 outfile\n", 33);
	exit(1);
}

void	err_des(char *c)
{
	if (errno == 0)
		write(2, "Error\n", 6);
	else
		perror(c);
	exit(1);
}

void	command_not_found(char **cmd)
{
	write(2, cmd[0], ft_strlen(cmd[0]));
	write(2, ": command not found\n", 20);
	free_tab(cmd);
	exit(1);
}

void	free_tab(char **str)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	if (str)
	{
		while (str[len])
			len++;
		while (i < len)
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}
