/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarqu / aluther-                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 00:00:00 by manmarqu          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/executor/executor.h"
#include "src/parser/parser.h"
#include <readline/readline.h>
#include <readline/history.h>

static void	process_line(char *line, t_shell *shell)
{
	t_cmd	*cmd;

	if (!line || !*line)
	{
		if (g_signal == SIGINT)
			shell->exit_code = 130;
		return ;
	}
	add_history(line);
	g_signal = 0;
	cmd = parse(line, shell);
	if (!cmd)
	{
		if (g_signal == SIGINT)
			shell->exit_code = 130;
		return ;
	}
	shell->exit_code = execute(cmd, shell);
	free_cmd_list(cmd);
}

static void	minishell_loop(t_shell *shell)
{
	char	*line;

	setup_signals_interactive();
	while (1)
	{
		g_signal = 0;
		line = readline("minishell$ ");
		if (g_signal == SIGINT)
		{
			free(line);
			shell->exit_code = 130;
			continue ;
		}
		if (!line)
		{
			write(1, "exit\n", 5);
			break ;
		}
		process_line(line, shell);
		free(line);
	}
}

static t_shell	init_shell(char **envp)
{
	t_shell	shell;

	shell.env_list = environment_reader(envp);
	shell.exit_code = 0;
	shell.pid = 0;
	return (shell);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argc;
	(void)argv;
	shell = init_shell(envp);
	if (!shell.env_list)
	{
		write(2, "minishell: failed to init environment\n", 38);
		return (1);
	}
	minishell_loop(&shell);
	free_list(shell.env_list);
	rl_clear_history();
	return (shell.exit_code);
}
