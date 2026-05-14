/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:35:54 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/17 20:35:57 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)str + i);
	return (NULL);
}

/*#include<stdio.h>
int	main()
{
	char str[] = "Gordas t3t4s";
	int c = 'a';
	char *result = ft_strchr(str, c);

	if(result == NULL)
			printf("No se ha encontrado coincidencias");
	else
		printf("Coincidencia "
		"encontrada:'%c' (resto: \"%s\")\n", *result, result);
	return 0;
	}*/
