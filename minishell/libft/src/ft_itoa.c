/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:17:47 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/27 17:17:49 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_len_calculator(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*number;
	int				l;
	unsigned int	num;

	l = ft_len_calculator(n);
	number = (char *)malloc((l + 1) * sizeof(char));
	if (!number)
		return (NULL);
	number[l] = '\0';
	if (n < 0)
	{
		number[0] = '-';
		num = -n;
	}
	else
		num = n;
	while (l-- > (n < 0))
	{
		number[l] = (num % 10) + '0';
		num /= 10;
	}
	return (number);
}

/*#include <stdio.h>
int	main()
{
	int n;
	char *result;

	n = -6654542;
	result = ft_itoa(n);
	printf("Resultado de imprimir %d: %s", n, result);
	return 0;
	}*/
