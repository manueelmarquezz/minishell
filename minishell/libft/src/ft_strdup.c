/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:39:21 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/26 13:39:23 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "../libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	int		len;

	len = ft_strlen(s) + 1;
	dst = (char *)malloc(len);
	if (!dst)
		return (NULL);
	ft_memcpy(dst, s, len);
	return (dst);
}

/*#include <stdio.h>

int main()
{
    char original[] = "Hola, mundo!";
    char *copia = ft_strdup(original);  // Llamar a tu función

    if (!copia) {
        printf("Error: No se pudo duplicar la cadena.\n");
        return 1;
    }

    printf("Cadena original: %s\n", original);
    printf("Cadena duplicada: %s\n", copia);

    free(copia);  // Liberar memoria para evitar fugas
    return 0;
}
*/
