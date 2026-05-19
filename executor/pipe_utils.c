/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- / manmarqu                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 00:00:00 by manmarqu          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static int	open_pipe(t_cmd *current, t_pipe_ctx *ctx)
{
	ctx->pipe_fd[0] = -1;
	ctx->pipe_fd[1] = -1;
	if (current->next && pipe(ctx->pipe_fd) == -1)
	{
		perror("minishell: pipe");
		return (-1);
	}
	return (0);
}

static pid_t	fork_cmd(t_cmd *cur, t_pipe_ctx *ctx, t_shell *shell)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (perror("minishell: fork"), (pid_t)(-1));
	if (pid == 0)
		exec_child(cur, ctx, shell);
	return (pid);
}

static int	iter_pipe(t_cmd **current, t_pipe_ctx *ctx,
				t_shell *shell, pid_t *last_pid)
{
	pid_t	pid;

	ctx->is_last = !(*current)->next;
	if (open_pipe(*current, ctx) == -1)
		return (-1);
	pid = fork_cmd(*current, ctx, shell);
	if (pid == -1)
	{
		if (ctx->prev_fd != -1)
			close(ctx->prev_fd);
		return (close_fds(ctx->pipe_fd[0], ctx->pipe_fd[1]), -1);
	}
	if (ctx->prev_fd != -1)
		close(ctx->prev_fd);
	if ((*current)->next)
	{
		close(ctx->pipe_fd[1]);
		ctx->prev_fd = ctx->pipe_fd[0];
	}
	*last_pid = pid;
	*current = (*current)->next;
	return (0);
}

int	exec_pipe(t_cmd *cmd, t_shell *shell)
{
	t_cmd		*current;
	t_pipe_ctx	ctx;
	pid_t		last_pid;

	ctx.prev_fd = -1;
	last_pid = -1;
	current = cmd;
	while (current)
	{
		if (iter_pipe(&current, &ctx, shell, &last_pid) == -1)
			return (1);
	}
	return (wait_all(last_pid));
}
