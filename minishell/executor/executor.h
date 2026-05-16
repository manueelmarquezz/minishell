/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- / manmarqu                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 00:00:00 by manmarqu          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "../libft/libft.h"
# include "../args_and_env/environment.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>
# include <string.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef enum e_redir_type
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_HEREDOC,
}	t_redir_type;

typedef struct s_redir
{
	t_redir_type	type;
	char			*file;
	int				heredoc_fd;
	struct s_redir	*next;
}	t_redir;

typedef struct s_cmd
{
	char			**args;
	t_redir			*redirs;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_shell
{
	t_env			*env_list;
	int				exit_code;
	pid_t			pid;
}	t_shell;

typedef struct s_pipe_ctx
{
	int		prev_fd;
	int		pipe_fd[2];
	int		is_last;
}	t_pipe_ctx;

extern volatile sig_atomic_t	g_signal;

int		execute(t_cmd *cmd, t_shell *shell);
int		exec_single(t_cmd *cmd, t_shell *shell);
int		exec_pipe(t_cmd *cmd, t_shell *shell);
void	exec_child(t_cmd *cmd, t_pipe_ctx *ctx, t_shell *shell);
char	**env_to_array(t_env *env_list);
char	*find_in_path(char *cmd_name, t_env *env_list);
int		exec_external(char **args, t_env *env_list, t_shell *shell);
int		apply_redirs(t_redir *redirs);
int		handle_heredoc(char *delim, t_shell *shell);
int		is_builtin(char *cmd_name);
int		exec_builtin(t_cmd *cmd, t_shell *shell);
void	close_fds(int fd1, int fd2);
void	free_cmd_list(t_cmd *cmd);
void	free_redir_list(t_redir *redir);
int		wait_all(pid_t last_pid);
void	exec_error(t_shell *shell, char *cmd, char *msg, int code);
int		delim_was_quoted(char *delim);
char	*clean_delim(char *delim);
void	write_line(int fd, char *line, int expand, t_shell *shell);
void	setup_signals_interactive(void);
void	setup_signals_child(void);
void	setup_signals_heredoc(void);
t_cmd	*parse(char *input, t_shell *shell);

#endif
