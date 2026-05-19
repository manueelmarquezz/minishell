/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:53:57 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/26 12:53:59 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	ptr = malloc(num * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, num * size);
	return (ptr);
}

/*#include <stdio.h>
int main() {
	int *arr = (int *)ft_calloc(9, sizeof(int));

	if (!arr)
	{
		printf("Error al asignar memoria.\n");
		return 1;
	}
	printf("Valores inicializados con ft_calloc:\n");
	for (int i = 0; i < 9; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr);
	return 0;
	}*/
