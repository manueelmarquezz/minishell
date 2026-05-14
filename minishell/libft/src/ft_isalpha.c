/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:08:33 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/13 22:54:40 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

/*#include <stdio.h>

int main ()
{
    int c;

    c = 'z';
    int result = ft_isalpha(c);

    if (result != 0)
        printf ("Is alphabet");
    if (result == 0)
        printf ("Not alphabet");
    return 0;
}*/
