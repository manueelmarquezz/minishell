/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:42:04 by manmarqu          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include <readline/readline.h>
#include <readline/history.h>

static int	is_numeric(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	get_exit_code(char *arg)
{
	int	code;

	code = ft_atoi(arg) % 256;
	if (code < 0)
		code = 256 + code;
	return (code);
}

int	exit_builtin(char **args, t_env **env_list)
{
	int	exit_code;

	write(2, "exit\n", 5);
	if (!args[1])
		exit_code = 0;
	else if (!is_numeric(args[1]))
	{
		write(2, "minishell: exit: ", 17);
		write(2, args[1], ft_strlen(args[1]));
		write(2, ": numeric argument required\n", 28);
		exit_code = 2;
	}
	else if (args[2])
	{
		write(2, "minishell: exit: too many arguments\n", 36);
		return (1);
	}
	else
		exit_code = get_exit_code(args[1]);
	free_list(*env_list);
	rl_clear_history();
	exit(exit_code);
	return (exit_code);
}
