/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 12:59:07 by aluther-          #+#    #+#             */
/*   Updated: 2025/12/27 12:59:08 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_strndup(const char *s, size_t n)
{
	char	*dst;
	size_t	i;

	dst = (char *)malloc(n + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < n && s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
