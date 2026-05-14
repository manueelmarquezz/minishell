/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:44:19 by manmarqu          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	free_env_node(t_env *node)
{
	if (!node)
		return ;
	free(node->env_name);
	free(node->env_value);
	free(node);
}

static void	remove_from_list(t_env **env_list, const char *name)
{
	t_env	*current;
	t_env	*prev;

	if (!env_list || !*env_list)
		return ;
	current = *env_list;
	prev = NULL;
	while (current)
	{
		if (ft_strcmp(current->env_name, (char *)name) == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				*env_list = current->next;
			if (current->next)
				current->next->previous = prev;
			free_env_node(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

void	unset(t_env **env_list, char *assigment)
{
	if (!assigment || !assigment[0])
		return ;
	remove_from_list(env_list, assigment);
}
