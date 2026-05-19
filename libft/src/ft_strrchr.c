/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 22:36:59 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/21 12:53:37 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (str[i])
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			j = i;
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)str + i);
	if (j != -1)
		return ((char *)str + j);
	return (NULL);
}

/*#include <stdio.h>

int main()
{
    char str[] = "Gordas tatasss";
    int c = 'a';
    char *result;

    result = ft_strrchr(str, c);

    if (result)
        printf("Ultima aparicion de caracter "
        "encontrada en %p, caracter: %c\n", (void*)result, *result);
    else
        printf("No se ha encontrado el caracter\n");

    return 0;
    }*/
