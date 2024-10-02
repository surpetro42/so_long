/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_cep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:10:38 by surpetro          #+#    #+#             */
/*   Updated: 2024/06/02 18:20:43 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	extraneou_synvoli(char **s)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (s[i])
	{
		l = 0;
		while (s[i][l])
		{
			if (s[i][l] != '1' && s[i][l] != '0' && s[i][l] != 'P'
				&& s[i][l] != 'E' && s[i][l] != 'C' && s[i][l] != 'F'
				&& s[i][l] != '\n' && s[i][l] != '\0')
				exit(write(2, "The symbols are wrong\n", 21));
			l++;
		}
		i++;
	}
}

void	search_c(char **s)
{
	int	i;
	int	l;
	int	count;

	i = 0;
	l = 0;
	count = 0;
	while (s[i])
	{
		l = 0;
		while (s[i][l])
		{
			if (s[i][l] == 'C')
				count++;
			l++;
		}
		i++;
	}
	if (count == 0)
		exit(write(2, "ERROR~\n", 7));
}

void	inspect_pe(int count1, int count2)
{
	if (count1 > 2 || count2 > 2)
		exit(write(2, "ERROR\n", 6));
	if (count1 == 0 || count2 == 0)
		exit(write(2, "ERROR\n", 6));
}

int	beginning_pe(char **s)
{
	int		i;
	int		l;
	int		count2;
	int		count1;

	i = 0;
	count1 = 0;
	count2 = 0;
	while (s[i])
	{
		l = 0;
		while (s[i][l])
		{
			if (s[i][l] == 'P')
				count1++;
			else if (s[i][l] == 'E')
				count2++;
			l++;
		}
		i++;
	}
	inspect_pe(count1, count2);
	return (1);
}

void	beginning_cep(char **s)
{
	int	i;

	i = 0;
	extraneou_synvoli(s);
	beginning_pe(s);
	search_c(s);
}
