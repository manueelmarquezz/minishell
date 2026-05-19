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

static void	read_lines(int fd, char *clean, int expand, t_shell *shell)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			write(2, "\nminishell: warning: heredoc delimited", 38);
			write(2, " by EOF (wanted `", 17);
			write(2, clean, ft_strlen(clean));
			write(2, "')\n", 3);
			break ;
		}
		if (ft_strcmp(line, clean) == 0)
		{
			free(line);
			break ;
		}
		write_line(fd, line, expand, shell);
		free(line);
	}
}

static void	heredoc_child(int fd, char *delim, int expand, t_shell *shell)
{
	char	*clean;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
	clean = clean_delim(delim);
	if (!clean)
		exit(1);
	read_lines(fd, clean, expand, shell);
	free(clean);
	close(fd);
	exit(0);
}

static int	wait_heredoc(int pipe_fd[2], pid_t pid)
{
	int	status;

	close(pipe_fd[1]);
	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	setup_signals_interactive();
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		close(pipe_fd[0]);
		g_signal = SIGINT;
		write(1, "\n", 1);
		return (-1);
	}
	return (pipe_fd[0]);
}

int	handle_heredoc(char *delim, t_shell *shell)
{
	int		pipe_fd[2];
	int		expand;
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		return (perror("minishell: heredoc pipe"), -1);
	expand = !delim_was_quoted(delim);
	pid = fork();
	if (pid == -1)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		return (perror("minishell: heredoc fork"), -1);
	}
	if (pid == 0)
	{
		close(pipe_fd[0]);
		heredoc_child(pipe_fd[1], delim, expand, shell);
	}
	return (wait_heredoc(pipe_fd, pid));
}
