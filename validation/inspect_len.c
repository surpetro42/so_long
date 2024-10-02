/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:10:38 by surpetro          #+#    #+#             */
/*   Updated: 2024/05/27 14:21:00 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	end_newline(char **s)
{
	size_t	i;
	size_t	l;
	int		buff;

	i = 0;
	l = 0;
	buff = 0;
	while (s[i])
	{
		l = 0;
		while (s[i][l])
		{
			if (l >= ft_strlen(s[0]))
			{
				buff = i;
				if (++buff == '\n' || ++buff == '\t' || ++buff == ' ')
					exit(write(2, "ERROR LEN\n", 10));
			}
			l++;
		}
		i++;
	}
}

void	comparison(char **s)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(s[i]);
	while (s[i])
	{
		if (len != ft_strlen(s[i]))
			exit(write(2, "The lines don't match\n", 22));
		i++;
	}
}

void	inspect_len(char **s)
{
	size_t	i;
	size_t	l;

	i = 0;
	comparison(s);
	end_newline(s);
	while (s[i])
	{
		l = 0;
		while (s[i][l])
		{
			if (l > ft_strlen(s[0]))
			{
				if (s[i][l] == ' ' || s[i][l] == '\t')
				{
					free(s[i]);
					s[i] = ft_strtrim(s[i], " ");
				}
			}
			l++;
		}
		i++;
	}
}
