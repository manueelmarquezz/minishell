/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 10:18:00 by aluther-          #+#    #+#             */
/*   Updated: 2025/06/07 10:18:02 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_putnbr(long n);
int		ft_putpositivenbr(unsigned int n);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_ptrtohex(uintptr_t p);
int		ft_nbrtohex(unsigned int p);
int		ft_uppernbrtohex(unsigned int p);
int		ft_hexlen(unsigned long ptr);
char	*ft_strtoupper(char *str);
int		ft_printf(char const *format, ...);
#endif
