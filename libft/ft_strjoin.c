/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:07:27 by rsham             #+#    #+#             */
/*   Updated: 2024/11/10 15:20:02 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		k;
	char	*n;
	int		j;

	k = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	n = (char *)malloc(i + j + 1);
	if (!n)
		return (NULL);
	i = 0;
	while (s1[i])
		n[k++] = s1[i++];
	j = 0;
	while (s2[j])
		n[k++] = s2[j++];
	n[k] = '\0';
	return (n);
}
