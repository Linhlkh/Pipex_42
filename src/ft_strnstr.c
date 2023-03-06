/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:35:37 by khle              #+#    #+#             */
/*   Updated: 2023/02/24 23:07:05 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!str1)
		return (NULL);
	if (!str2 || !str2[0])
		return ((char *)str1);
	while (i < n && str1[i])
	{
		j = 0;
		while (str1[i + j] == str2[j] && str2[j] && i + j < n)
			j++;
		if (!str2[j])
			return ((char *)(str1 + i));
		i++;
	}
	return (0);
}
/*#include<stdio.h>
int main()
{
const char str1[]= "";
const char str2[] = "xsx";
printf("%s", ft_strnstr(str1, str2, 15));

}*/