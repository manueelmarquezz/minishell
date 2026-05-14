/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:55:32 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/21 12:55:33 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		c -= 32;
	return (c);
}

/*#include<stdio.h>
int	main()
{
	char c1 = 'A';
	char c2 = 'b';
	char c3 = 'w';
	char c4 = '5';

	printf("La letra %c en minuscula es %c\n", c1, ft_toupper(c1));
	printf("La letra %c en minuscula es %c\n", c2, ft_toupper(c2));
	printf("La letra %c en minuscula es %c\n", c3, ft_toupper(c3));
	printf("La letra %c en minuscula es %c\n", c4, ft_toupper(c4));
  return 0;
  }*/
