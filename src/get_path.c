/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:17:51 by khle              #+#    #+#             */
/*   Updated: 2023/03/07 04:31:48 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

char	**get_paths(char **envp)
{
	char	**paths;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!envp || !envp[0])
		return (NULL);
	while (envp[len])
		len++;
	while (envp[i] && !(ft_strnstr(envp[i], "PATH", 4)))
		i++;
	if (i != len)
	{
		paths = ft_split(envp[i] + 5, ':');
		if (paths)
			return (paths);
	}
	return (NULL);
}

int	ft_cmd_is_pathname(char *cmd)
{
	if (ft_strnstr(cmd, "/", (ft_strlen(cmd))))
	{
		if (access(cmd, F_OK) == 0)
			return (1);
		else
			err_des(cmd);
	}
	return (0);
}

char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*check;
	char	*check1;
	int		i;

	i = 0;
	paths = get_paths(envp);
	if (ft_cmd_is_pathname(cmd) == 1 || !paths)
		return (cmd);
	while (paths[i])
	{
		check = ft_strjoin(paths[i], "/");
		check1 = ft_strjoin(check, cmd);
		free(check);
		if (!access(check1, F_OK | X_OK))
		{
			free_tab(paths);
			return (check1);
		}
		free(check1);
		i++;
	}
	free_tab(paths);
	return (NULL);
}
