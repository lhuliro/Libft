/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuliro- <lhuliro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:27:53 by lhuliro-          #+#    #+#             */
/*   Updated: 2023/03/31 17:28:43 by lhuliro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	int		start;
	int		end;
	char	*trim;

	start = 0;
	if (!*s)
		return (ft_calloc(1, 1));
	trim = (char *) s;
	while (ft_strchr(set, trim[start]))
		start++;
	end = ft_strlen(trim) - 1;
	while (ft_strchr(set, trim[end]) && end > start)
		end--;
	return (ft_substr(trim, start, end - start + 1));
}
