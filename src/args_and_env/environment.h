/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 13:49:55 by manmarqu          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "../../libft/libft.h"
# include <stdlib.h>

typedef struct s_env
{
	char			*env_name;
	char			*env_value;
	struct s_env	*next;
	struct s_env	*previous;
}	t_env;

void	free_list(t_env *head);
t_env	*new_env_node(char *env_str);
t_env	*environment_reader(char **envp);
int		update_existing_var(t_env *env_list, char *name, char *value);
void	print_env_var(t_env *env_list, char *var_name);
void	modify_env_var(t_env **env_list, char *assignment);
t_env	*find_env_var(t_env *env_list, const char *name);
int		create_new_var(t_env **env_list, char *var_name, char *value);

#endif
