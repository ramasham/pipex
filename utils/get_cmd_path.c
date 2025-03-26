/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:18:24 by rsham             #+#    #+#             */
/*   Updated: 2025/03/27 02:22:29 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    *check_argv(char *cmd)
{
	if (cmd == NULL || is_whitespace(cmd) == 1)
		return (NULL);
	return (cmd);
}

static char	**get_path_dirs(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == NULL)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	return (paths);
}

static char	*join_path_and_cmd(char *path, char *cmd)
{
	char	*part_path;
	char	*full_path;

	part_path = ft_strjoin(path, "/");
	if (!part_path)
		return (NULL);
	full_path = ft_strjoin(part_path, cmd);
	if (!full_path)
	{
		free(part_path);
		return (NULL);
	}
	free(part_path);
	return (full_path);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;

	paths = get_path_dirs(envp);
	if (!paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		path = join_path_and_cmd(paths[i], cmd);
		if (!path)
			return (NULL);
		if (path && access(path, F_OK) == 0)
		{
			ft_free(paths);
			return (path);
		}
		free(path);
	}
	ft_free(paths);
	return (NULL);
}
