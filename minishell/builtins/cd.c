/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:51:47 by manmarqu          #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by manmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static char	*get_env_val(t_env *env_list, const char *name)
{
	t_env	*current;

	current = env_list;
	while (current)
	{
		if (ft_strcmp(current->env_name, (char *)name) == 0)
			return (current->env_value);
		current = current->next;
	}
	return (NULL);
}

static void	set_env_var(t_env **env_list, const char *name, const char *val)
{
	t_env	*current;
	t_env	*node;

	current = *env_list;
	while (current)
	{
		if (ft_strcmp(current->env_name, (char *)name) == 0)
		{
			free(current->env_value);
			current->env_value = ft_strdup(val);
			return ;
		}
		current = current->next;
	}
	node = malloc(sizeof(t_env));
	if (!node)
		return ;
	node->env_name = ft_strdup(name);
	node->env_value = ft_strdup(val);
	node->next = *env_list;
	node->previous = NULL;
	if (*env_list)
		(*env_list)->previous = node;
	*env_list = node;
}

static int	cd_error(const char *msg, const char *arg)
{
	write(2, "cd: ", 4);
	if (arg)
	{
		write(2, arg, ft_strlen(arg));
		write(2, ": ", 2);
	}
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	return (1);
}

static char	*resolve_path(char **args, t_env *env_list, int *print_flag)
{
	char	*path;

	if (!args[1] || ft_strcmp(args[1], "~") == 0)
	{
		path = get_env_val(env_list, "HOME");
		if (!path)
			return (cd_error("HOME not set", NULL), NULL);
	}
	else if (ft_strcmp(args[1], "-") == 0)
	{
		path = get_env_val(env_list, "OLDPWD");
		if (!path)
			return (cd_error("OLDPWD not set", NULL), NULL);
		*print_flag = 1;
	}
	else
		path = args[1];
	return (path);
}

int	cd(char **args, t_env **env_list)
{
	char	oldpwd[4096];
	char	newpwd[4096];
	char	*path;
	int		print_flag;

	if (args[1] && args[2])
		return (cd_error("too many arguments", NULL));
	if (!getcwd(oldpwd, sizeof(oldpwd)))
		return (cd_error("error getting current directory", NULL));
	print_flag = 0;
	path = resolve_path(args, *env_list, &print_flag);
	if (!path)
		return (1);
	if (print_flag)
	{
		write(1, path, ft_strlen(path));
		write(1, "\n", 1);
	}
	if (chdir(path) != 0)
		return (cd_error("No such file or directory", path));
	if (!getcwd(newpwd, sizeof(newpwd)))
		return (cd_error("error retrieving new directory", NULL));
	set_env_var(env_list, "OLDPWD", oldpwd);
	set_env_var(env_list, "PWD", newpwd);
	return (0);
}
