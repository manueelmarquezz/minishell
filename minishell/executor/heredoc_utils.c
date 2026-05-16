/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:44:02 by manmarqu          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "../parser/parser.h"

int	delim_was_quoted(char *delim)
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

char	*clean_delim(char *delim)
{
	char	*clean;
	int		i;
	int		j;

	clean = malloc(ft_strlen(delim) + 1);
	if (!clean)
		return (NULL);
	i = 0;
	j = 0;
	while (delim[i])
	{
		if (delim[i] != '\x01' && delim[i] != '\x02')
			clean[j++] = delim[i];
		i++;
	}
	clean[j] = '\0';
	return (clean);
}

void	write_line(int fd, char *line, int expand, t_shell *shell)
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
