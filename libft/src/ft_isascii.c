/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:24:57 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/13 22:55:16 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*#include <stdio.h>
int	main ()
{
	int c = '\0';    // IMPUT HERE
	int result = ft_isascii(c);

	if (result == 0)
		printf ("Oh no, is not ASCII ;( \n RETURNED VALUE %d", result);
	if (result == 1)
		printf(":D OMG WE FOUND AN ASCII \n RETURNED VALUE %d", result);
	return 0;
	}*/
