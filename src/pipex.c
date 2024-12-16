/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:52:33 by rsham             #+#    #+#             */
/*   Updated: 2024/12/16 18:05:44 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

static void	ft_close(int *fd)
{
	close(fd[1]);
	close(fd[0]);
	exit(1);
}

static void	wait_parent(int *fd)
{
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid = fork();
		if (pid == -1)
			ft_close(fd);
		if (pid == 0)
			child_process(argv, envp, fd);
		pid = fork();
		if (pid == -1)
			ft_close(fd);
		if (pid == 0)
			child_process2(argv, envp, fd);
		wait_parent(fd);
		return (0);
	}
	write(2, "Error\n", 6);
	exit (1);
}
