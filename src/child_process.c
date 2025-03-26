/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:19:30 by rsham             #+#    #+#             */
/*   Updated: 2025/03/27 02:21:14 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	if (check_argv(argv) == NULL)
		exit(1);
	cmd = ft_split(argv, ' ');
	path = get_cmd_path(cmd[0], envp);
	if (!path)
	{
		ft_free(cmd);
		cmd_error(argv);
		return (-1);
	}
	if (execve(path, cmd, envp) == -1)
	{
		ft_free(cmd);
		free(path);
		return (-1);
	}
	return (0);
}

void	child_process(char **argv, char **envp, int *fd)
{
	int	infile;
	int	exec;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		close(fd[1]);
		close(fd[0]);
		error();
	}
	close(fd[0]);
	if (dup2(infile, STDIN_FILENO) < 0)
		error();
	dup2(fd[1], STDOUT_FILENO);
	close(infile);
	close(fd[1]);
	exec = execute(argv[2], envp);
	if (exec == -1)
		error();
	exit(1);
}

void	child_process2(char **argv, char **envp, int *fd)
{
	int	outfile;
	int	exec;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
	{
		close(fd[0]);
		close(fd[1]);
		error();
	}
	close(fd[1]);
	dup2(outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(outfile);
	close(fd[0]);
	exec = execute(argv[3], envp);
	if (exec == -1)
		error();
	exit(1);
}
