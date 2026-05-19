/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarqu / aluther-                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 00:00:00 by manmarqu          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	handle_marker(char *str, int *i, int *in_single)
{
	if (str[*i] == '\x01')
	{
		*in_single = !(*in_single);
		(*i)++;
		return (1);
	}
	if (str[*i] == '\x02')
	{
		(*i)++;
		return (1);
	}
	return (0);
}

static int	should_expand(char c, int in_single)
{
	if (in_single)
		return (0);
	return (c == '$');
}

static int	is_expandable(char next)
{
	return (ft_isalnum(next) || next == '_' || next == '?');
}

static char	*expand_char(char *str, int *i, t_shell *shell, int in_single)
{
	char	buf[2];
	char	*tmp;

	if (should_expand(str[*i], in_single) && is_expandable(str[*i + 1]))
	{
		tmp = expand_var(str, i, shell);
		return (tmp);
	}
	buf[0] = str[(*i)++];
	buf[1] = '\0';
	return (ft_strdup(buf));
}

char	*expand_str(char *str, t_shell *shell)
{
	char	*result;
	char	*tmp;
	int		i;
	int		in_single;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 0;
	in_single = 0;
	while (str[i])
	{
		if (handle_marker(str, &i, &in_single))
			continue ;
		tmp = expand_char(str, &i, shell, in_single);
		if (!tmp)
		{
			free(result);
			return (NULL);
		}
		result = strjoin_free(result, tmp);
		free(tmp);
	}
	return (result);
}
