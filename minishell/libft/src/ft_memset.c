/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:02:28 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/21 16:45:14 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *ptr, int value, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}

/*#include <stdio.h>

int main(void)
{
    char str[20] = "Hola, mundo!";
    int value = '*';
    int n = 15;

    printf("Antes de ft_memset: %s\n", str);
    ft_memset(str, value, n);
    printf("Después de ft_memset: %s\n", str);

    return 0;
}*/
