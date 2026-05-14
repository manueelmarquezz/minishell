/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarqu / aluther-                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 00:00:00 by manmarqu          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_itoa_buf(int n, char *buf)
{
	char	tmp[16];
	int		i;
	int		j;
	int		neg;

	neg = (n < 0);
	if (neg)
		n = -n;
	i = 0;
	if (n == 0)
		tmp[i++] = '0';
	while (n > 0)
	{
		tmp[i++] = '0' + (n % 10);
		n /= 10;
	}
	j = 0;
	if (neg)
		buf[j++] = '-';
	while (i > 0)
		buf[j++] = tmp[--i];
	buf[j] = '\0';
}

char	*strjoin_free(char *s1, char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

static char	*get_var_value(char *name, t_shell *shell)
{
	t_env	*node;

	node = find_env_var(shell->env_list, name);
	if (node && node->env_value)
		return (ft_strdup(node->env_value));
	return (ft_strdup(""));
}

char	*expand_var(char *str, int *i, t_shell *shell)
{
	char	name[256];
	char	exit_str[16];
	int		j;

	(*i)++;
	if (str[*i] == '?')
	{
		(*i)++;
		ft_itoa_buf(shell->exit_code, exit_str);
		return (ft_strdup(exit_str));
	}
	j = 0;
	while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_') && j < 255)
		name[j++] = str[(*i)++];
	name[j] = '\0';
	if (j == 0)
		return (ft_strdup("$"));
	return (get_var_value(name, shell));
}
