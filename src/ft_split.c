/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:09:09 by khle              #+#    #+#             */
/*   Updated: 2023/02/24 23:06:58 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == 0))
			j++;
		i++;
	}
	return (j);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (finish - start + 1));
	if (!word)
		return (NULL);
	while (start < finish)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**list;
	size_t	i;
	size_t	j;
	int		start;

	i = 0;
	j = 0;
	start = -1;
	list = (char **) malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!list || !s)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			list[j] = word_dup(s, start, i);
			j++;
			start = -1;
		}
		i++;
	}
	list[j] = 0;
	return (list);
}
/*#include<stdio.h>
int main()
{
    char const c[50]="";
    char s = ' ';
	//char **list = ft_split(c, s);
	//int i = 0;
	//while(list[i])
	//{
    //printf("%s", list[i]);
	//i++;
	//}
	printf("%d", count_words(c,s));
}*/