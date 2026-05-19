/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:41:40 by manmarqu          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	close_fds(int fd1, int fd2)
{
	if (fd1 >= 0)
		close(fd1);
	if (fd2 >= 0)
		close(fd2);
}

void	exec_error(t_shell *shell, char *cmd, char *msg, int code)
{
	write(2, "minishell: ", 11);
	if (cmd)
	{
		write(2, cmd, ft_strlen(cmd));
		write(2, ": ", 2);
	}
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	if (shell)
		shell->exit_code = code;
}

static int	get_last_status(pid_t pid, int status, pid_t last_pid)
{
	if (pid != last_pid)
		return (-1);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGQUIT)
			write(2, "Quit (core dumped)\n", 19);
		else if (WTERMSIG(status) == SIGINT)
			write(1, "\n", 1);
		return (128 + WTERMSIG(status));
	}
	return (WEXITSTATUS(status));
}

int	wait_all(pid_t last_pid)
{
	pid_t	pid;
	int		status;
	int		last_status;
	int		tmp;

	last_status = 0;
	while (1)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == -1)
			break ;
		tmp = get_last_status(pid, status, last_pid);
		if (tmp != -1)
			last_status = tmp;
	}
	return (last_status);
}
