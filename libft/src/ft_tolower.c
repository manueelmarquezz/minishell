/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolower.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:02:43 by aluther           #+#    #+#             */
/*   Updated: 2025/05/21 12:46:17 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		c += 32;
	return (c);
}

/*#include<stdio.h>
int	main()
{
	char c1 = 'A';
	char c2 = 'b';
	char c3 = 'V';
	char c4 = '5';

	printf("La letra %c en minuscula es %c\n", c1, ft_tolower(c1));
	printf("La letra %c en minuscula es %c\n", c2, ft_tolower(c2));
	printf("La letra %c en minuscula es %c\n", c3, ft_tolower(c3));
	printf("La letra %c en minuscula es %c\n", c4, ft_tolower(c4));
  return 0;
  }*/
