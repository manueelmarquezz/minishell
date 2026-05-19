/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarqu / aluther-                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 00:00:00 by manmarqu          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	append_cmd(t_cmd **head, t_cmd **tail, t_cmd *cmd)
{
	if (!*head)
	{
		*head = cmd;
		*tail = cmd;
	}
	else
	{
		(*tail)->next = cmd;
		*tail = cmd;
	}
}

static int	syntax_pipe_err(t_token *tokens, t_cmd *head)
{
	write(2, "minishell: syntax error near `|'\n", 33);
	free_tokens(tokens);
	free_cmd_list(head);
	return (1);
}

static int	advance_pipe(t_token **tok, t_token *tokens, t_cmd *head)
{
	if (!*tok || (*tok)->type != TOKEN_PIPE)
		return (0);
	*tok = (*tok)->next;
	if (!*tok)
		return (syntax_pipe_err(tokens, head));
	return (0);
}

static int	parse_next(t_token **tok, t_shell *shell,
				t_cmd **head, t_cmd **tail)
{
	t_cmd	*cmd;

	cmd = parse_cmd(tok, shell);
	if (!cmd)
		return (1);
	if (cmd->args || cmd->redirs)
		append_cmd(head, tail, cmd);
	else
		free(cmd);
	return (0);
}

t_cmd	*parse(char *input, t_shell *shell)
{
	t_token	*tokens;
	t_token	*tok;
	t_cmd	*head;
	t_cmd	*tail;

	if (!input)
		return (NULL);
	tokens = lexer(input);
	if (!tokens)
		return (NULL);
	head = NULL;
	tail = NULL;
	tok = tokens;
	while (tok)
	{
		if (tok->type == TOKEN_PIPE)
			return (syntax_pipe_err(tokens, head), NULL);
		if (parse_next(&tok, shell, &head, &tail))
			return (free_tokens(tokens), free_cmd_list(head), NULL);
		if (advance_pipe(&tok, tokens, head))
			return (NULL);
	}
	free_tokens(tokens);
	return (head);
}
