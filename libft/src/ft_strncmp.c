/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:07:25 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/17 19:00:01 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*#include <stdio.h>
#include <string.h>
int	main()
{
	char s1[] = "HolA!";
	char s2[] = "jshlB?";
	int n = 3;
	int final_result;
	int ref;

	final_result = ft_strncmp(s1,	s2, n);
	ref = strncmp(s1, s2, n);
	if (final_result == 0)
		printf("Los primeros %d caracteres de las dos str son iguales."
		"Valor retornado %d."
		"Valor de comparacion con strlcmp %d\n", n, final_result, ref);
	if(final_result > 0)
		printf("Los primeros %d carateres de las dos funciones son diferentes.
		"Valor retornado %d."
		"Valor de comparacion con strlcmp %d\n", n, final_result, ref);
	if(final_result < 0)
		printf("Los primeros %d caracteres de las dos funciones son diferentes."
		"Valor retornado %d."
		"Valor de comparacion con strlcmp %d\n", n, final_result, ref);
	return (0);
	}*/
