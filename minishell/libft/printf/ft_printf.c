/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 11:30:12 by aluther-          #+#    #+#             */
/*   Updated: 2025/06/08 11:30:14 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printspecifier(const char *format, va_list args, int i, int *len)
{
	if (format[i] == 'c')
		*len += ft_putchar((char)va_arg(args, int));
	if (format[i] == 's')
		*len += ft_putstr((char *)va_arg(args, char *));
	if (format[i] == 'p')
		*len += ft_ptrtohex((unsigned long)va_arg(args, void *));
	if (format[i] == 'd' || format[i] == 'i')
		*len += ft_putnbr((int)va_arg(args, int));
	if (format[i] == 'u')
		*len += ft_putpositivenbr((unsigned int)va_arg(args, unsigned int));
	if (format[i] == 'x')
		*len += ft_nbrtohex((unsigned long)va_arg(args, unsigned long));
	if (format[i] == 'X')
		*len += ft_uppernbrtohex((unsigned long)va_arg(args, unsigned long));
	if (format[i] == '%')
		*len += ft_putchar('%');
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_printspecifier(format, args, i, &len);
		}
		else
		{
			ft_putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
