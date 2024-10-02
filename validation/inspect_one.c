/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:10:38 by surpetro          #+#    #+#             */
/*   Updated: 2024/05/23 16:12:03 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	beginning_end(char *s, int len)
{
	if (s[0] != '1')
	{
		free(s);
		exit(write(2, "beginning NO ONE\n", 17));
	}
	if (s[len - 1] != '1')
	{
		free(s);
		exit(write(2, "end NO ONE\n", 11));
	}
}

void	not_alone(char c, char **s)
{
	if (c != '1')
	{
		free(s);
		exit(write(2, "boundary NO ONE\n", 16));
	}
}

void	inspect_one(char **s)
{
	int	i;
	int	l;
	int	len_arr;
	int	len_str;

	i = 0;
	len_arr = arrlen(s);
	while (s[i])
	{
		len_str = ft_strlen(s[i]);
		beginning_end(s[i], len_str);
		l = 0;
		while (s[i][l])
		{
			if (i == 0 || i == len_arr - 1)
				not_alone(s[i][l], s);
			else if (s[i][l] <= 32)
				l++;
			else
				if (l == 0 || l == len_str - 1)
					not_alone(s[i][l], s);
			l++;
		}
		i++;
	}
}
