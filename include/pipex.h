/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:42:48 by rsham             #+#    #+#             */
/*   Updated: 2024/12/15 13:50:04 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

int		execute(char *argv, char **envp);
void	child_process(char **argv, char **envp, int *fd);
void	child_process2(char **argv, char **envp, int *fd);
void	error(void);
void	ft_free(char **str);
char	*get_cmd_path(char *cmd, char **envp);
void	cmd_error(char *argv);
int		is_whitespace(const char *cmd);
int		ft_isspace(int ch);

#endif
