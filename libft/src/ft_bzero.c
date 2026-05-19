/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:55:20 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/21 16:45:56 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t n)
{
	ft_memset(ptr, 0, n);
}

/*#include<stdio.h>
int main()
{
    char str[] = "Hola gordiiiiii";
    int c = 5;
    printf("Cadena original: %s\n", str);
    ft_bzero(str, c);
    printf("Cadena tras borrado: %s\n", str);
    return 0;
    }*/
