/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 00:00:00 by manmarqu          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static char	*make_env_str(t_env *node)
{
	char	*tmp;
	char	*result;

	tmp = ft_strjoin(node->env_name, "=");
	if (!tmp)
		return (NULL);
	if (node->env_value)
		result = ft_strjoin(tmp, node->env_value);
	else
		result = ft_strjoin(tmp, "");
	free(tmp);
	return (result);
}

static int	fill_envp(char **envp, t_env *env_list)
{
	int	i;

	i = 0;
	while (env_list)
	{
		envp[i] = make_env_str(env_list);
		if (!envp[i])
		{
			while (i-- > 0)
				free(envp[i]);
			return (-1);
		}
		env_list = env_list->next;
		i++;
	}
	envp[i] = NULL;
	return (0);
}

char	**env_to_array(t_env *env_list)
{
	char	**envp;
	t_env	*cur;
	int		size;

	size = 0;
	cur = env_list;
	while (cur && ++size)
		cur = cur->next;
	envp = malloc(sizeof(char *) * (size + 1));
	if (!envp)
		return (NULL);
	if (fill_envp(envp, env_list) == -1)
		return (free(envp), NULL);
	return (envp);
}

int	exec_external(char **args, t_env *env_list, t_shell *shell)
{
	char	*path;
	char	**envp;
	int		i;

	path = find_in_path(args[0], env_list);
	if (!path)
		return (exec_error(shell, args[0], "command not found", 127), 127);
	envp = env_to_array(env_list);
	if (!envp)
	{
		free(path);
		return (exec_error(shell, args[0], "memory allocation failed", 1), 1);
	}
	execve(path, args, envp);
	perror(args[0]);
	free(path);
	i = 0;
	while (envp[i])
		free(envp[i++]);
	free(envp);
	exec_error(shell, args[0], strerror(errno), 126);
	return (126);
}
