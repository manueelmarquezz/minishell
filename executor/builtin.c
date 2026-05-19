/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:25:19 by manmarqu          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "../builtins/builtins.h"

int	is_builtin(char *cmd_name)
{
	if (!cmd_name)
		return (0);
	return (ft_strcmp(cmd_name, "echo") == 0
		|| ft_strcmp(cmd_name, "cd") == 0
		|| ft_strcmp(cmd_name, "pwd") == 0
		|| ft_strcmp(cmd_name, "export") == 0
		|| ft_strcmp(cmd_name, "unset") == 0
		|| ft_strcmp(cmd_name, "env") == 0
		|| ft_strcmp(cmd_name, "exit") == 0);
}

static int	exec_export(t_cmd *cmd, t_shell *shell)
{
	int	i;

	if (!cmd->args[1])
		b_export(&shell->env_list, "");
	else
	{
		i = 1;
		while (cmd->args[i])
			b_export(&shell->env_list, cmd->args[i++]);
	}
	return (0);
}

static int	exec_unset(t_cmd *cmd, t_shell *shell)
{
	int	i;

	i = 1;
	while (cmd->args[i])
		unset(&shell->env_list, cmd->args[i++]);
	return (0);
}

int	exec_builtin(t_cmd *cmd, t_shell *shell)
{
	char	**args;

	args = cmd->args;
	if (ft_strcmp(args[0], "echo") == 0)
		return (echo(args));
	if (ft_strcmp(args[0], "pwd") == 0)
		return (pwd(args));
	if (ft_strcmp(args[0], "cd") == 0)
		return (cd(args, &shell->env_list));
	if (ft_strcmp(args[0], "env") == 0)
		return (env(shell->env_list), 0);
	if (ft_strcmp(args[0], "exit") == 0)
		return (exit_builtin(args, &shell->env_list));
	if (ft_strcmp(args[0], "export") == 0)
		return (exec_export(cmd, shell));
	if (ft_strcmp(args[0], "unset") == 0)
		return (exec_unset(cmd, shell));
	return (1);
}
