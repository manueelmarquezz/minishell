/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:50:35 by aluther-          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	valid_variable_name(char *assigment)
{
	int	i;

	i = 1;
	if (!(assigment[0] == '_'
			|| (assigment[0] >= 'A' && assigment[0] <= 'Z')
			|| (assigment[0] >= 'a' && assigment[0] <= 'z')))
		return (0);
	while (assigment[i] && assigment[i] != '=')
	{
		if (!((assigment[i] >= 'a' && assigment[i] <= 'z')
				|| (assigment[i] >= 'A' && assigment[i] <= 'Z')
				|| (assigment[i] >= '0' && assigment[i] <= '9')
				|| assigment[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

static void	print_one(t_env *node)
{
	write(1, "declare -x ", 11);
	write(1, node->env_name, ft_strlen(node->env_name));
	if (node->env_value)
	{
		write(1, "=\"", 2);
		write(1, node->env_value, ft_strlen(node->env_value));
		write(1, "\"", 1);
	}
	write(1, "\n", 1);
}

static void	print_export(t_env *env_list)
{
	t_env	**env_array;
	int		size;
	int		i;

	size = env_list_size(env_list);
	if (size == 0)
		return ;
	env_array = malloc(sizeof(t_env *) * size);
	if (!env_array)
		return ;
	fill_env_array(env_array, env_list);
	sort_env_array(env_array, size);
	i = 0;
	while (i < size)
		print_one(env_array[i++]);
	free(env_array);
}

void	b_export(t_env **env_list, char *assigment)
{
	while (*assigment == ' ')
		assigment++;
	if (*assigment == '\0')
		print_export(*env_list);
	else
	{
		if (!valid_variable_name(assigment))
		{
			write(2, "minishell: export: `", 20);
			write(2, assigment, ft_strlen(assigment));
			write(2, "': not a valid identifier\n", 26);
			return ;
		}
		modify_env_var(env_list, assigment);
	}
}
