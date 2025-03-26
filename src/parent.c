/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:52:33 by rsham             #+#    #+#             */
/*   Updated: 2025/03/27 02:19:55 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
