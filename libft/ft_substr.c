/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:51:01 by rsham             #+#    #+#             */
/*   Updated: 2024/08/31 12:14:17 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*n;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		n = (char *)malloc(sizeof(char));
		if (n)
			n[0] = '\0';
		return (n);
	}
	if (start + len > s_len)
		len = s_len - start;
	n = (char *)malloc(len + 1);
	if (!n)
		return (NULL);
	ft_memcpy(n, s + start, len);
	n[len] = '\0';
	return (n);
}
