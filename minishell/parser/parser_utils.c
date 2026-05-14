/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarqu / aluther-                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 00:00:00 by manmarqu          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_redir	*new_redir(t_redir_type type, char *file, int heredoc_fd)
{
	t_redir	*r;

	r = malloc(sizeof(t_redir));
	if (!r)
		return (NULL);
	r->type = type;
	r->file = file;
	r->heredoc_fd = heredoc_fd;
	r->next = NULL;
	return (r);
}

void	append_redir(t_cmd *cmd, t_redir *r)
{
	t_redir	*cur;

	if (!r)
		return ;
	if (!cmd->redirs)
	{
		cmd->redirs = r;
		return ;
	}
	cur = cmd->redirs;
	while (cur->next)
		cur = cur->next;
	cur->next = r;
}

int	count_args(t_token *tok)
{
	int	n;

	n = 0;
	while (tok && tok->type == TOKEN_WORD)
	{
		n++;
		tok = tok->next;
	}
	return (n);
}

static int	fill_args(char **args, t_token **tok, t_shell *shell)
{
	int	i;

	i = 0;
	while (*tok && (*tok)->type == TOKEN_WORD)
	{
		args[i] = expand_str((*tok)->value, shell);
		if (!args[i])
		{
			while (i > 0)
				free(args[--i]);
			return (-1);
		}
		i++;
		*tok = (*tok)->next;
	}
	args[i] = NULL;
	return (0);
}

char	**build_args(t_token **tok, t_shell *shell)
{
	int		n;
	char	**args;

	n = count_args(*tok);
	if (n == 0)
		return (NULL);
	args = malloc(sizeof(char *) * (n + 1));
	if (!args)
		return (NULL);
	if (fill_args(args, tok, shell) == -1)
		return (free(args), NULL);
	return (args);
}
