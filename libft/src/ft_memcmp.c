/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 09:43:09 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/24 09:43:38 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>


int ft_memcmp(const void *s1, const void *s2, size_t n);

int main(void)
{
    char a[] = "Hola";
    char b[] = "Holb";
    int res1 = ft_memcmp(a, b, 4);
    int res2 = memcmp(a, b, 4);

    printf("ft_memcmp: %d\n", res1);
    printf("memcmp:    %d\n", res2);

    return 0;
}*/
