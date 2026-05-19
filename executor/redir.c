/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- / manmarqu                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 00:00:00 by manmarqu          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static int	apply_redir_in(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(2, "minishell: ", 11);
		write(2, file, ft_strlen(file));
		write(2, ": No such file or directory\n", 28);
		return (-1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
		return (close(fd), -1);
	close(fd);
	return (0);
}

static int	apply_redir_out(char *file, int append)
{
	int	fd;
	int	flags;

	if (append)
		flags = O_WRONLY | O_CREAT | O_APPEND;
	else
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	fd = open(file, flags, 0644);
	if (fd == -1)
	{
		write(2, "minishell: ", 11);
		write(2, file, ft_strlen(file));
		write(2, ": Permission denied\n", 20);
		return (-1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (close(fd), -1);
	close(fd);
	return (0);
}

static int	apply_one(t_redir *cur)
{
	if (cur->type == REDIR_IN)
		return (apply_redir_in(cur->file));
	if (cur->type == REDIR_OUT)
		return (apply_redir_out(cur->file, 0));
	if (cur->type == REDIR_APPEND)
		return (apply_redir_out(cur->file, 1));
	if (cur->heredoc_fd < 0)
		return (-1);
	if (dup2(cur->heredoc_fd, STDIN_FILENO) == -1)
		return (-1);
	close(cur->heredoc_fd);
	return (0);
}

int	apply_redirs(t_redir *redirs)
{
	while (redirs)
	{
		if (apply_one(redirs) == -1)
			return (-1);
		redirs = redirs->next;
	}
	return (0);
}
