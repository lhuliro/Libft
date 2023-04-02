/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuliro- <lhuliro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:34:50 by lhuliro-          #+#    #+#             */
/*   Updated: 2023/03/31 17:28:43 by lhuliro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s1, int c, size_t n)
{
	unsigned char	c1;
	unsigned char	*s;
	size_t			i;

	s = (unsigned char *)s1;
	c1 = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (c1 == s[i])
			return (&s[i]);
		i++;
	}
	return (NULL);
}
