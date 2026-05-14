/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:27:49 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/22 16:29:38 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(void *str, int ch, int n)
{
	int				i;
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char) ch)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}

/*#include<stdio.h>
int main()
{
    char str[] = "Hola mundo!";
    int ch = 'm';
    int n = 6;
    char *ptr;

    ptr = ft_memchr(str, ch, n);

    if (ptr != 0)
        printf("El carácter '%c' encontrado "
        "en la posición: %ld\n", ch, ptr - str);
    else
        printf("El carácter '%c' no se encuentra en la cadena.\n", ch);
    return 0;
    }*/
