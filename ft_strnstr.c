/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuliro- <lhuliro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:54:34 by lhuliro-          #+#    #+#             */
/*   Updated: 2023/03/31 17:28:43 by lhuliro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_needle;
	size_t	len_haystack;

	i = 0;
	len_needle = ft_strlen(needle);
	len_haystack = ft_strlen(haystack);
	if (len_needle == 0)
		return ((char *) haystack);
	while (i < len_haystack)
	{
		if (haystack[i] == needle[0] && i + len_needle <= len)
			if (ft_strncmp(&haystack[i], needle, len_needle) == 0)
				return ((char *) haystack + i);
		i++;
	}
	return (NULL);
}
