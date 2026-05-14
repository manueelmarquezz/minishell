/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- / manmarqu                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 00:00:00 by manmarqu          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	setup_io(t_pipe_ctx *ctx)
{
	if (ctx->prev_fd != -1)
	{
		if (dup2(ctx->prev_fd, STDIN_FILENO) == -1)
			exit(1);
		close(ctx->prev_fd);
	}
	if (!ctx->is_last)
	{
		close(ctx->pipe_fd[0]);
		if (dup2(ctx->pipe_fd[1], STDOUT_FILENO) == -1)
			exit(1);
		close(ctx->pipe_fd[1]);
	}
	else
	{
		close_fds(ctx->pipe_fd[0], ctx->pipe_fd[1]);
	}
}

void	exec_child(t_cmd *cmd, t_pipe_ctx *ctx, t_shell *shell)
{
	setup_signals_child();
	setup_io(ctx);
	if (apply_redirs(cmd->redirs) == -1)
		exit(1);
	if (is_builtin(cmd->args[0]))
		exit(exec_builtin(cmd, shell));
	exit(exec_external(cmd->args, shell->env_list, shell));
}
