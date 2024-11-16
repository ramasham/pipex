/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:44:52 by rsham             #+#    #+#             */
/*   Updated: 2024/08/29 17:42:48 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	tol_size;
	void	*n;

	tol_size = nmemb * size;
	n = malloc(tol_size);
	if (!n)
		return (NULL);
	ft_bzero(n, tol_size);
	return (n);
}
