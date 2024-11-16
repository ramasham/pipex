/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:52:33 by rsham             #+#    #+#             */
/*   Updated: 2024/11/14 18:06:04 by rsham            ###   ########.fr       */
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
	exec = execute(argv[2], envp, fd);
	if (exec == -1)
		error();
	exit(0);
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
	exec = execute(argv[3], envp, fd);
	if (exec == -1)
		error();
	exit(0);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (access(argv[1], R_OK) == -1 || ((access(argv[4], F_OK) == 0)
				&& (access(argv[4], W_OK) == -1)))
			error();
		if (pipe(fd) == -1)
			error();
		pid = fork();
		if (pid == -1)
			return (close(fd[0]), close(fd[1]), 0);
		if (pid == 0)
			child_process(argv, envp, fd);
		pid = fork();
		if (pid == -1)
			return (close(fd[0]), close(fd[1]), 0);
		if (pid == 0)
			child_process2(argv, envp, fd);
		return (close(fd[0]), close(fd[1]), wait(NULL), wait(NULL), 0);
	}
	write(2, "Error\n", 6);
	return (0);
}
