/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarqu / aluther-                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 00:00:00 by manmarqu          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_token	*new_token(t_token_type type, char *value)
{
	t_token	*tok;

	tok = malloc(sizeof(t_token));
	if (!tok)
		return (NULL);
	tok->type = type;
	tok->value = value;
	tok->next = NULL;
	return (tok);
}

void	free_tokens(t_token *tokens)
{
	t_token	*tmp;

	while (tokens)
	{
		tmp = tokens->next;
		free(tokens->value);
		free(tokens);
		tokens = tmp;
	}
}

static t_token_type	get_op_type(char *input, int i)
{
	if (input[i] == '|')
		return (TOKEN_PIPE);
	if (input[i] == '<' && input[i + 1] == '<')
		return (TOKEN_REDIR_HEREDOC);
	if (input[i] == '>' && input[i + 1] == '>')
		return (TOKEN_REDIR_APPEND);
	if (input[i] == '<')
		return (TOKEN_REDIR_IN);
	return (TOKEN_REDIR_OUT);
}

static void	lex_operator(char *input, int *i,
				t_token **head, t_token **tail)
{
	t_token_type	type;
	char			*val;

	type = get_op_type(input, *i);
	if (type == TOKEN_REDIR_HEREDOC || type == TOKEN_REDIR_APPEND)
	{
		if (type == TOKEN_REDIR_HEREDOC)
			val = ft_strdup("<<");
		else
			val = ft_strdup(">>");
		*i += 2;
	}
	else
	{
		val = ft_strndup(input + *i, 1);
		(*i)++;
	}
	append_token(head, tail, new_token(type, val));
}

t_token	*lexer(char *input)
{
	t_token	*head;
	t_token	*tail;
	int		i;

	if (!input || unclosed_quotes(input))
		return (NULL);
	head = NULL;
	tail = NULL;
	i = 0;
	while (input[i])
	{
		while (input[i] == ' ' || input[i] == '\t')
			i++;
		if (!input[i])
			break ;
		if (input[i] == '|' || input[i] == '<' || input[i] == '>')
			lex_operator(input, &i, &head, &tail);
		else
			append_token(&head, &tail,
				new_token(TOKEN_WORD, read_word(input, &i)));
	}
	return (head);
}
