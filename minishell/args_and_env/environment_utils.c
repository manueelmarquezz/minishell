/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:08:26 by manmarqu          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

int	update_existing_var(t_env *env_list, char *name, char *value)
{
	t_env	*current;

	current = env_list;
	while (current)
	{
		if (ft_strcmp(current->env_name, name) == 0)
		{
			free(current->env_value);
			current->env_value = ft_strdup(value);
			return (1);
		}
		current = current->next;
	}
	return (0);
}

int	create_new_var(t_env **env_list, char *var_name, char *value)
{
	t_env	*new_node;

	new_node = malloc(sizeof(t_env));
	if (!new_node)
		return (0);
	new_node->env_name = ft_strdup(var_name);
	new_node->env_value = ft_strdup(value);
	if (!new_node->env_name || !new_node->env_value)
	{
		free(new_node->env_name);
		free(new_node->env_value);
		free(new_node);
		return (0);
	}
	new_node->next = *env_list;
	new_node->previous = NULL;
	if (*env_list)
		(*env_list)->previous = new_node;
	*env_list = new_node;
	return (1);
}

static void	modify_no_equal(t_env **env_list, char *assignment)
{
	char	*var_name;
	char	*value;

	var_name = ft_strdup(assignment);
	if (!var_name)
		return (free(assignment));
	if (!find_env_var(*env_list, var_name))
	{
		value = ft_strdup("");
		if (!value)
		{
			free(var_name);
			return (free(assignment));
		}
		create_new_var(env_list, var_name, value);
		free(value);
	}
	free(var_name);
	free(assignment);
}

static void	modify_with_equal(t_env **env_list, char *assignment,
				char *equal_pos)
{
	char	*var_name;
	char	*value;

	var_name = ft_strndup(assignment, equal_pos - assignment);
	value = ft_strdup(equal_pos + 1);
	if (!var_name || !value)
	{
		free(var_name);
		free(value);
		free(assignment);
		return ;
	}
	if (!update_existing_var(*env_list, var_name, value))
		create_new_var(env_list, var_name, value);
	free(value);
	free(var_name);
	free(assignment);
}

void	modify_env_var(t_env **env_list, char *assignment)
{
	char	*equal_pos;

	assignment = ft_strtrim(assignment, " \t\n");
	if (!assignment)
		return ;
	equal_pos = ft_strchr(assignment, '=');
	if (!equal_pos)
		modify_no_equal(env_list, assignment);
	else
		modify_with_equal(env_list, assignment, equal_pos);
}
