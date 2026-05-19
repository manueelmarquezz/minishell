/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:50:44 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/26 15:50:48 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rsl;
	int		i;
	int		j;

	i = 0;
	j = 0;
	rsl = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (char));
	if (rsl == NULL)
		return (NULL);
	while (s1[j] != '\0')
	{
		rsl[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		rsl[i] = s2[j];
		i++;
		j++;
	}
	rsl[i] = '\0';
	return (rsl);
}

/*#include <stdio.h>
int main()
{
	char *s1 = "Hola ";
	char *s2 = "mundo......";
	char *rslt;

	rslt = ft_strjoin(s1, s2);
	printf("Cadena resultante: %s", rslt);
	return 0;
}*/
