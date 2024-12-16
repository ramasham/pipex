/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erros.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:03:01 by rsham             #+#    #+#             */
/*   Updated: 2024/12/15 13:32:02 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("error");
	exit(1);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	cmd_error(char *argv)
{
	int	j;
	int	i;

	j = 0;
	i = ft_strlen(argv);
	write(2, "command not found: ", 19);
	while (i--)
		write(2, &argv[j++], 1);
	write(2, "\n", 1);
	exit(1);
}

int	ft_isspace(int ch)
{
	int	result;

	result = 0;
	if (ch == ' ')
		result = 1;
	if (ch == '\t')
		result = 1;
	if (ch == '\n')
		result = 1;
	return (result);
}

int	is_whitespace(const char *cmd)
{
	int	i;

	i = 0;
	if (cmd == NULL || *cmd == '\0')
		return (1);
	while (cmd[i] != '\0')
	{
		if (!ft_isspace((unsigned char)cmd[i]))
			return (0);
		i++;
	}
	return (1);
}
