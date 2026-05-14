/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarqu / aluther-                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 00:00:00 by manmarqu          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_redir_type	op_to_redir(t_token_type op)
{
	if (op == TOKEN_REDIR_IN)
		return (REDIR_IN);
	if (op == TOKEN_REDIR_OUT)
		return (REDIR_OUT);
	if (op == TOKEN_REDIR_APPEND)
		return (REDIR_APPEND);
	return (REDIR_HEREDOC);
}

static t_redir	*build_redir(t_token_type op, char *raw, t_shell *shell)
{
	int		fd;
	char	*clean;

	fd = -1;
	if (op == TOKEN_REDIR_HEREDOC)
		fd = handle_heredoc(raw, shell);
	clean = expand_str(raw, shell);
	if (!clean)
		return (NULL);
	return (new_redir(op_to_redir(op), clean, fd));
}

int	parse_redir(t_token **tok, t_cmd *cmd, t_shell *shell)
{
	t_token_type	op_type;
	char			*raw;
	t_redir			*r;

	op_type = (*tok)->type;
	*tok = (*tok)->next;
	if (!*tok || (*tok)->type != TOKEN_WORD)
	{
		write(2, "minishell: syntax error near token\n", 35);
		return (-1);
	}
	raw = (*tok)->value;
	*tok = (*tok)->next;
	r = build_redir(op_type, raw, shell);
	if (!r)
		return (-1);
	append_redir(cmd, r);
	return (0);
}

static t_cmd	*new_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = NULL;
	cmd->redirs = NULL;
	cmd->next = NULL;
	return (cmd);
}

t_cmd	*parse_cmd(t_token **tok, t_shell *shell)
{
	t_cmd	*cmd;
	int		total;

	cmd = new_cmd();
	if (!cmd)
		return (NULL);
	total = 0;
	while (*tok && (*tok)->type != TOKEN_PIPE)
	{
		if ((*tok)->type == TOKEN_WORD)
		{
			if (add_args_to_cmd(tok, cmd, shell, &total) == -1)
				return (free_cmd_list(cmd), NULL);
		}
		else if (parse_redir(tok, cmd, shell) == -1)
			return (free_cmd_list(cmd), NULL);
	}
	return (cmd);
}
