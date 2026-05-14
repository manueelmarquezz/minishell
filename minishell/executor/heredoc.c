/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:44:02 by manmarqu          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "../parser/parser.h"

static int	delim_was_quoted(char *delim)
{
	int	i;

	i = 0;
	while (delim[i])
	{
		if (delim[i] == '\x01' || delim[i] == '\x02')
			return (1);
		i++;
	}
	return (0);
}

static void	write_line(int fd, char *line, int expand, t_shell *shell)
{
	char	*expanded;

	if (expand)
	{
		expanded = expand_str(line, shell);
		if (expanded)
		{
			write(fd, expanded, ft_strlen(expanded));
			free(expanded);
		}
	}
	else
		write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
}

static void	warn_eof(char *delim)
{
	write(2, "\nminishell: warning: heredoc delimited", 38);
	write(2, " by EOF (wanted `", 17);
	write(2, delim, ft_strlen(delim));
	write(2, "')\n", 3);
}

static int	read_heredoc(int fd, char *delim, int expand, t_shell *shell)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			if (g_signal != SIGINT)
				warn_eof(delim);
			return (g_signal == SIGINT);
		}
		if (ft_strcmp(line, delim) == 0)
			return (free(line), 0);
		write_line(fd, line, expand, shell);
		free(line);
	}
}

int	handle_heredoc(char *delim, t_shell *shell)
{
	int	pipe_fd[2];
	int	expand;
	int	interrupted;

	if (pipe(pipe_fd) == -1)
		return (perror("minishell: heredoc pipe"), -1);
	expand = !delim_was_quoted(delim);
	setup_signals_heredoc();
	interrupted = read_heredoc(pipe_fd[1], delim, expand, shell);
	close(pipe_fd[1]);
	setup_signals_interactive();
	if (interrupted || g_signal == SIGINT)
		return (close(pipe_fd[0]), -1);
	return (pipe_fd[0]);
}
