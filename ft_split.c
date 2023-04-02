/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuliro- <lhuliro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:29:58 by lhuliro-          #+#    #+#             */
/*   Updated: 2023/03/31 17:28:43 by lhuliro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number_of_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		if (((s[i] != c) && i == 0) || ((s[i] != c) && (s[i - 1] == c)))
			count ++;
		i ++;
	}
	return (count);
}

static void	ft_sub_split(char *str, char c, char **tab, int num_words)
{
	char	*nstr;
	int		i;
	int		j;

	j = 0;
	while (j < num_words)
	{
		i = 0;
		while (str[i] != c && str[i] != 0)
			i++;
		if (str[i] == 0 && i > 0)
		{
			tab[j] = ft_substr(str, 0, i);
			j++;
			free (str);
			break ;
		}
		tab[j] = ft_substr(str, 0, i);
		nstr = ft_strtrim(str + i, (char [2]){(char) c, '\0'});
		free (str);
		str = nstr;
		j++;
	}
	tab[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*str;
	char	*set;
	int		num_words;

	num_words = ft_number_of_words(s, c);
	tab = (char **) malloc((sizeof(char *) * (num_words + 1)));
	if (num_words == 0)
	{
		*tab = NULL;
		return (tab);
	}
	if (!tab)
		return (NULL);
	str = (char *) s;
	set = (char [2]){(char) c, '\0'};
	str = ft_strtrim(str, set);
	ft_sub_split(str, c, tab, num_words);
	return (tab);
}
