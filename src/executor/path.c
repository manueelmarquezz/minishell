/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:42:10 by manmarqu          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static char	*get_path_value(t_env *env_list)
{
	while (env_list)
	{
		if (ft_strcmp(env_list->env_name, "PATH") == 0)
			return (env_list->env_value);
		env_list = env_list->next;
	}
	return (NULL);
}

static char	*try_path(char *dir, char *cmd_name)
{
	char	*tmp;
	char	*full;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	full = ft_strjoin(tmp, cmd_name);
	free(tmp);
	if (!full)
		return (NULL);
	if (access(full, X_OK) == 0)
		return (full);
	free(full);
	return (NULL);
}

static char	*search_dirs(char **dirs, char *cmd_name)
{
	char	*found;
	int		i;

	i = 0;
	found = NULL;
	while (dirs[i] && !found)
		found = try_path(dirs[i++], cmd_name);
	i = 0;
	while (dirs[i])
		free(dirs[i++]);
	free(dirs);
	return (found);
}

char	*find_in_path(char *cmd_name, t_env *env_list)
{
	char	*path_val;
	char	**dirs;

	if (!cmd_name)
		return (NULL);
	if (ft_strchr(cmd_name, '/'))
	{
		if (access(cmd_name, X_OK) == 0)
			return (ft_strdup(cmd_name));
		return (NULL);
	}
	path_val = get_path_value(env_list);
	if (!path_val)
		return (NULL);
	dirs = ft_split(path_val, ':');
	if (!dirs)
		return (NULL);
	return (search_dirs(dirs, cmd_name));
}
