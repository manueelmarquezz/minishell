/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:13:54 by aluther           #+#    #+#             */
/*   Updated: 2025/05/21 12:51:35 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	if (*needle == '\0')
		return ((char *)haystack);
	needle_len = 0;
	while (needle[needle_len])
		needle_len++;
	i = 0;
	while (i + needle_len <= size && haystack[i])
	{
		j = 0;
		while (j < needle_len && haystack[i + j] == needle[j])
			j++;
		if (j == needle_len)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
int main()
{
    char haystack[] = "Holasoy jose";
    char needle[] = "jose";
    int size = 12;

    char *p = ft_strnstr(haystack, needle, size);

    if(p == 0)
        printf("Coincidencia no encontrada");
    else
        printf("Coincidendia encontrada");
    return (0);
    }
*/
