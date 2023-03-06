/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:57:06 by khle              #+#    #+#             */
/*   Updated: 2023/02/24 23:07:00 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

char
	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc
		(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = 0;
	return (str);
}

/*char    *ft_strjoin(char const *s1, char const *s2)
{
    size_t i;
    size_t j;
    char    *str;

    i = 0;
    j = 0;
    str = (char *) malloc (sizeof(s1) * (ft_strlen(s1) + ft_strlen(s2)+1));
    if (!str)
        return (NULL);
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        str[i + j] = s2[j];
        j++;
    }
    str[i + j] = 0;
    return(str);
}
*/
/*#include<stdio.h>
int main()
{
    char c1[20] = "hello";
    char c2[20] = "how are you?";
    printf("%s", ft_strjoin(c1, c2));
}
*/
