/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 11:53:20 by aluther-          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../args_and_env/environment.h"
# include <unistd.h>
# include <stdlib.h>

void	env(t_env *env_list);
void	b_export(t_env **env_list, char *assigment);
void	fill_env_array(t_env **env_array, t_env *env_list);
void	sort_env_array(t_env **env_array, int size);
void	unset(t_env **env_list, char *assigment);
int		echo(char **args);
int		pwd(char **args);
int		exit_builtin(char **args, t_env **env_list);
int		cd(char **args, t_env **env_list);
int		env_list_size(t_env *env_list);

#endif
