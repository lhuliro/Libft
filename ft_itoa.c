/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuliro- <lhuliro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:31:15 by lhuliro-          #+#    #+#             */
/*   Updated: 2023/03/31 17:28:43 by lhuliro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_number_of_digits(int n)
{
	size_t	count;

	count = 1;
	if (n > 0)
		count--;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*num;
	size_t	size;
	long	nbr;

	nbr = n;
	if (nbr < 0)
		nbr *= -1;
	size = ft_number_of_digits(n);
	num = malloc(size + 1);
	if (!num)
		return (NULL);
	num[size] = '\0';
	size--;
	while (nbr > 0)
	{
		num[size] = (nbr % 10) + '0';
		nbr /= 10;
		size--;
	}
	if (size == 0 && num[1] == '\0')
		num[0] = '0';
	else if (size == 0 && num[1] != '\0')
		num[0] = '-';
	return (num);
}

// static size_t	ft_count_num(int n)
// {
// 	size_t	count;

// 	if (n > 0)
// 		count = 0;
// 	else
// 		count = 1;
// 	while (n != 0)
// 	{
// 		n /= 10;
// 		count++;
// 	}
// 	return (count);
// }

// char	*ft_itoa(int n)
// {
// 	char	*num;
// 	size_t	size;
// 	long	nbr;

// 	nbr = n;
// 	if (nbr < 0)
// 		nbr *= -1;
// 	size = ft_count_num(n);
// 	num = malloc (sizeof(char) * (size + 1));
// 	if (!num)
// 		return (NULL);
// 	num[size] = '\0';
// 	size--;
// 	while (nbr > 0)
// 	{
// 		num[size] = (nbr % 10) + '0';
// 		nbr /= 10;
// 		size--;
// 	}
// 	if (size == 0 && num[1] == '\0')
// 		num[0] = '0';
// 	else if (size == 0 && num[1] != '\0')
// 		num[0] = '-';
// 	return (num);
// }