/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 00:00:00 by manmarqu          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	fill_env_array(t_env **env_array, t_env *env_list)
{
	int	i;

	i = 0;
	while (env_list)
	{
		env_array[i] = env_list;
		env_list = env_list->next;
		i++;
	}
}

void	sort_env_array(t_env **env_array, int size)
{
	int		sorted;
	int		i;
	t_env	*tmp;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < size - 1)
		{
			if (ft_strcmp(env_array[i]->env_name,
					env_array[i + 1]->env_name) > 0)
			{
				tmp = env_array[i];
				env_array[i] = env_array[i + 1];
				env_array[i + 1] = tmp;
				sorted = 0;
			}
			i++;
		}
	}
}
