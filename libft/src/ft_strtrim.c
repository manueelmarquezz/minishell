/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:17:50 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/26 18:17:52 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*res;
	int		i;

	start = 0;
	i = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	res = (char *)malloc((end - start + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (start < end)
	{
		res[i] = s1[start];
		start++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*#include<stdio.h>
int main()
{
	char s1[] = "123Hola mundo3f21";
	char set[] = "123";
	char *result;

	result = ft_strtrim(s1, set);
	printf("Resultado: %s", result);
	return (0);
	}*/
