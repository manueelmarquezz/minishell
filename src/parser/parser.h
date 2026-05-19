/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarqu / aluther-                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 00:00:00 by manmarqu          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../executor/executor.h"

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_REDIR_APPEND,
	TOKEN_REDIR_HEREDOC,
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
	struct s_token	*next;
}	t_token;

t_token	*lexer(char *input);
t_token	*new_token(t_token_type type, char *value);
void	free_tokens(t_token *tokens);
char	*read_word(char *input, int *i);
int		unclosed_quotes(char *input);
void	append_token(t_token **head, t_token **tail, t_token *tok);
char	*expand_str(char *str, t_shell *shell);
char	*expand_var(char *str, int *i, t_shell *shell);
char	*strjoin_free(char *s1, char *s2);
void	ft_itoa_buf(int n, char *buf);
t_cmd	*parse(char *input, t_shell *shell);
t_cmd	*parse_cmd(t_token **tok, t_shell *shell);
int		parse_redir(t_token **tok, t_cmd *cmd, t_shell *shell);
t_redir	*new_redir(t_redir_type type, char *file, int heredoc_fd);
void	append_redir(t_cmd *cmd, t_redir *r);
int		count_args(t_token *tok);
char	**build_args(t_token **tok, t_shell *shell);
char	**merge_args(char **old, int total, char **tmp, int n);
int		add_args_to_cmd(t_token **tok, t_cmd *cmd, t_shell *shell, int *total);

#endif
