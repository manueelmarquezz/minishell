/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 21:49:48 by aluther-          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include <unistd.h>

void	free_list(t_env *head)
{
	t_env	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head->env_name);
		free(head->env_value);
		free(head);
		head = tmp;
	}
}

t_env	*find_env_var(t_env *env_list, const char *name)
{
	while (env_list)
	{
		if (ft_strcmp(env_list->env_name, name) == 0)
			return (env_list);
		env_list = env_list->next;
	}
	return (NULL);
}

t_env	*new_env_node(char *env_str)
{
	t_env	*new_node;
	char	*equal_pos;

	new_node = malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	equal_pos = ft_strchr(env_str, '=');
	if (equal_pos)
	{
		new_node->env_name = ft_strndup(env_str, equal_pos - env_str);
		new_node->env_value = ft_strdup(equal_pos + 1);
	}
	else
	{
		new_node->env_name = ft_strdup(env_str);
		new_node->env_value = ft_strdup("");
	}
	if (!new_node->env_name || !new_node->env_value)
		return (free(new_node->env_name), free(new_node->env_value),
			free(new_node), NULL);
	new_node->next = NULL;
	new_node->previous = NULL;
	return (new_node);
}

t_env	*environment_reader(char **envp)
{
	int		i;
	t_env	*head;
	t_env	*new_node;

	i = 0;
	head = NULL;
	while (envp[i])
	{
		new_node = new_env_node(envp[i]);
		if (!new_node)
			return (free_list(head), NULL);
		new_node->next = head;
		new_node->previous = NULL;
		if (head)
			head->previous = new_node;
		head = new_node;
		i++;
	}
	return (head);
}

void	print_env_var(t_env *env_list, char *var_name)
{
	t_env	*current;
	char	*clean_name;

	clean_name = ft_strtrim(var_name, " \t\n");
	if (!clean_name)
		return ;
	current = env_list;
	while (current)
	{
		if (ft_strcmp(current->env_name, clean_name) == 0)
		{
			write(1, current->env_value, ft_strlen(current->env_value));
			write(1, "\n", 1);
			return (free(clean_name));
		}
		current = current->next;
	}
	write(2, "Variable not found\n", 19);
	free(clean_name);
}
