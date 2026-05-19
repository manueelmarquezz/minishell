/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 09:48:01 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/24 09:48:03 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t					i;
	unsigned char			*d;
	const unsigned char		*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*#include <stdio.h>
#include <string.h>

int main(void)
{
    char origen[] = "Hola mundo";
    char destino[20];

    ft_memcpy(destino, origen, sizeof(origen));

    printf("Origen:  %s\n", origen);
    printf("Destino: %s\n", destino);

    char destino_std[20];
    memcpy(destino_std, origen, sizeof(origen));
    printf("Destino estándar: %s\n", destino_std);

    return 0;
}*/
