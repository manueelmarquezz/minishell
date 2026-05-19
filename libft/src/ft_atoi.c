/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:32:15 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/13 22:53:01 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		if ((str[i + 1] == '-' || str[i + 1] == '+'))
			return (0);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/*#include <stdio.h>
#include <stdlib.h>
int main()
{
    int f;
    int ref;
    char str[] = "+s344asd";

    f = ft_atoi(str);
    ref = atoi(str);
    printf("Conversion to integer with ft_atoi: %d", f);
    printf("\n");
    printf("Conversion with of atoi: %d", ref);
    return (0);
    }*/
