/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:17:55 by khle              #+#    #+#             */
/*   Updated: 2023/03/07 04:32:53 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

void	child_process(char **argv, char **envp, int *pipefd, int *fd)
{
	char	**cmd;
	char	*path;

	close(pipefd[0]);
	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] < 0)
		err_des(argv[1]);
	cmd = ft_split(argv[2], ' ');
	path = get_path(cmd[0], envp);
	dup2(pipefd[1], 1);
	dup2(fd[0], 0);
	close(fd[0]);
	if (cmd[0] && path)
	{
		if (execve(path, cmd, envp) == -1)
		{
			free_tab(cmd);
			if (!path)
				free(path);
			exit(1);
		}
	}
	else
		command_not_found(cmd);
}

void	parent_process(char **argv, char **envp, int *pipefd, int *fd)
{
	char	**cmd;
	char	*path;

	close(pipefd[1]);
	fd[1] = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (fd[1] < 0)
		err_des(argv[4]);
	cmd = ft_split(argv[3], ' ');
	path = get_path(cmd[0], envp);
	dup2(pipefd[0], 0);
	dup2(fd[1], 1);
	close(fd[1]);
	if (cmd[0] && path)
	{
		if (execve(path, cmd, envp) == -1)
		{
			free_tab(cmd);
			if (!path)
				free(path);
			exit(1);
		}
	}
	else
		command_not_found(cmd);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	int		fd[2];
	pid_t	pi_fork1;
	pid_t	pi_fork2;

	if (argc != 5)
		ac_error();
	if (pipe(pipefd) == -1)
		err_des(NULL);
	pi_fork1 = fork();
	if (pi_fork1 < 0)
		err_des("fork1");
	if (pi_fork1 == 0)
		child_process(argv, envp, pipefd, fd);
	if (pi_fork1 > 0)
		close(pipefd[1]);
	pi_fork2 = fork();
	if (pi_fork2 < 0)
		err_des("fork2");
	if (pi_fork2 == 0)
		parent_process(argv, envp, pipefd, fd);
	if (pi_fork2 > 0)
		close(pipefd[0]);
	return (0);
}
