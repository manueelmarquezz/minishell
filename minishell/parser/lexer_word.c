/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarqu / aluther-                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 00:00:00 by manmarqu          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	read_single_quote(char *input, int *i, char *buf, int *j)
{
	(*i)++;
	buf[(*j)++] = '\x01';
	while (input[*i] && input[*i] != '\'')
		buf[(*j)++] = input[(*i)++];
	if (input[*i] == '\'')
		(*i)++;
	buf[(*j)++] = '\x01';
}

static void	read_double_quote(char *input, int *i, char *buf, int *j)
{
	(*i)++;
	buf[(*j)++] = '\x02';
	while (input[*i] && input[*i] != '"')
		buf[(*j)++] = input[(*i)++];
	if (input[*i] == '"')
		(*i)++;
	buf[(*j)++] = '\x02';
}

static int	is_word_end(char c)
{
	return (c == ' ' || c == '\t' || c == '|'
		|| c == '<' || c == '>' || c == '\0');
}

char	*read_word(char *input, int *i)
{
	char	*buf;
	int		j;
	char	*result;

	buf = malloc(ft_strlen(input) * 3 + 16);
	if (!buf)
		return (NULL);
	j = 0;
	while (input[*i] && !is_word_end(input[*i]))
	{
		if (input[*i] == '\'')
			read_single_quote(input, i, buf, &j);
		else if (input[*i] == '"')
			read_double_quote(input, i, buf, &j);
		else
			buf[j++] = input[(*i)++];
	}
	buf[j] = '\0';
	result = ft_strdup(buf);
	free(buf);
	return (result);
}
