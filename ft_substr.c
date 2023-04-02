/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuliro- <lhuliro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:04:49 by lhuliro-          #+#    #+#             */
/*   Updated: 2023/03/31 17:28:43 by lhuliro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_str;
	size_t			i;
	size_t			j;
	unsigned int	s_len;

	s_len = (unsigned int) ft_strlen(s);
	if (!s)
		return (NULL);
	else if (!*s || start > s_len)
		return (ft_calloc(1, 1));
	if (len > s_len - start)
		len = s_len - start;
	sub_str = (char *) malloc(len + 1);
	if (!sub_str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
			sub_str[j++] = s[i];
		i++;
	}
	sub_str[j] = '\0';
	return (sub_str);
}
