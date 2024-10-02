/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:37:22 by surpetro          #+#    #+#             */
/*   Updated: 2024/06/10 21:04:43 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	itoa_len(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
	}
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*zerocase(char *m)
{
	m = (char *)malloc(sizeof(char) * 2);
	m[0] = 0 + '0';
	m[1] = 0;
	return (m);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	long	tmp_n;

	res = NULL;
	if (n == 0)
		return (zerocase(res));
	len = itoa_len(n);
	tmp_n = (long)n;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (tmp_n < 0)
	{
		res[0] = '-';
		tmp_n *= -1;
	}
	res[len] = '\0';
	len--;
	while (tmp_n != 0)
	{
		res[len--] = (tmp_n % 10) + '0';
		tmp_n = tmp_n / 10;
	}
	return (res);
}
