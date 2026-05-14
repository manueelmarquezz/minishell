/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:49:30 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/21 12:43:56 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_size;
	size_t	dst_size;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (size <= dst_size)
		return (src_size + size);
	i = dst_size;
	j = 0;
	while (i < size - 1 && src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (src_size + dst_size);
}

/*#include<stdio.h>

int	main()
{
	int return_value;
	char dst[9] = "Hola";
	char src[] = "Mundo";
	int	size = 9;

	return_value = ft_strlcat(dst, src, size);
	printf("Cadena resultante %s\n", dst);
	printf("Valor de retorno %d\n", return_value);
	return(0);
}*/
