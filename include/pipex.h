/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:42:48 by rsham             #+#    #+#             */
/*   Updated: 2024/11/12 15:11:05 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include "../libft/libft.h"

int		execute(char *argv, char **envp, int *fd);
void	child_process(char **argv, char **envp, int *fd);
void	child_process2(char **argv, char **envp, int *fd);
void	error(void);
void	ft_free(char **str);
char	*get_cmd_path(char *cmd, char **envp);

#endif
