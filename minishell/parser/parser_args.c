/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarqu / aluther-                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 00:00:00 by manmarqu          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**merge_args(char **old, int total, char **tmp, int n)
{
	char	**new_args;
	int		i;

	new_args = malloc(sizeof(char *) * (total + n + 1));
	if (!new_args)
		return (NULL);
	i = 0;
	while (i < total)
	{
		new_args[i] = old[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		new_args[total + i] = tmp[i];
		i++;
	}
	new_args[total + n] = NULL;
	free(old);
	free(tmp);
	return (new_args);
}

static int	count_strs(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	add_args_to_cmd(t_token **tok, t_cmd *cmd, t_shell *shell, int *total)
{
	char	**tmp;
	char	**merged;
	int		n;

	tmp = build_args(tok, shell);
	if (!tmp)
		return (0);
	n = count_strs(tmp);
	merged = merge_args(cmd->args, *total, tmp, n);
	if (!merged)
		return (-1);
	cmd->args = merged;
	*total += n;
	return (0);
}
