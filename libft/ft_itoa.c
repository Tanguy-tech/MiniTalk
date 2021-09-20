/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:47:54 by tbillon           #+#    #+#             */
/*   Updated: 2021/07/26 08:40:30 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sizenum(int x)
{
	size_t	i;

	i = 0;
	if (x == 0)
		return (1);
	if (!x)
		return (0);
	while (x != 0)
	{
		x = x / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;

	len = ft_sizenum(n);
	res = malloc(sizeof(char) * (len + 1));
	if (!(res))
		return (0);
	res[len] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		if (n == -2147483648)
		{
			res[1] = '2';
			n += 2000000000;
		}
		n *= -1;
	}
	while (n != 0)
	{
		res[--len] = (n % 10) + 48;
		n = n / 10;
	}
	return (res);
}
