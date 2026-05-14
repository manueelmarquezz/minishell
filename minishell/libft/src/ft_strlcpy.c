/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:50:34 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/15 18:30:29 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	src_size;

	src_size = 0;
	while (src[src_size] != '\0')
		src_size++;
	if (size > 0)
	{
		i = 0;
		while ((src[i] != '\0') && (i < (size - 1)))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_size);
}

/*#include <stdio.h>

int main()
{
    char    dst[] = "";
    char    src[] = "Hola, mundo!";
    int rtn;
    int size = 12;
    rtn = ft_strlcpy(dst, src, size);

    printf("Valor en dst tras copia: %s\n", dst);
    printf("Buffer asignado %d\n", size);
    printf("Valor retornado %d\n", rtn);

    return 0;
    }*/
