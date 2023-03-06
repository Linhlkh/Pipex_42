/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:02:39 by khle              #+#    #+#             */
/*   Updated: 2023/03/05 20:36:14 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *c);
char		*ft_strnstr(const char *str1, const char *str2, size_t n);
void		ac_error(void);
void		err_des(char *c);
void		command_not_found(char **cmd);
void		free_tab(char **str);
char		**get_paths(char **envp);
char		*get_path(char *cmd, char **envp);
void		child_process(char **argv, char **envp, int *pipefd, int *fd);
void		parent_process(char **argv, char **envp, int *pipefd, int *fd);

#endif