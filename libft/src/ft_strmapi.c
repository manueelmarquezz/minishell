/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:03:09 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/27 19:03:11 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*res;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*#include <stdio.h>
#include <stdlib.h>

char example_function(unsigned int i, char c)
{
    if (i % 2 == 1)
        return c - 32;
    return c;
}

int main(void)
{
    const char *str = "hola mundo";
    char *result;

    result = ft_strmapi(str, example_function);
    if (!result)
    {
        printf("Error: No se pudo asignar memoria.\n");
        return (1);
    }

    printf("Cadena original: %s\n", str);
    printf("Cadena transformada: %s\n", result);

    free(result);

    return (0);
}
*/
