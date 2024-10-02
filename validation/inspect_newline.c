/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_newline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:10:38 by surpetro          #+#    #+#             */
/*   Updated: 2024/06/10 22:28:13 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_probel_newline(char *line)
{
	int	i;
	int	buff;

	i = 0;
	if (!line || !line[i])
		return ;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
		{
			buff = i;
			buff++;
			if (line[buff] == '1')
			{
				buff -= 1;
				if (line[buff] == ' ' || line[buff] == '\t')
					exit(write(2, "ERROR probel or newline\n", 24));
				else
					break ;
			}
		}
		i++;
	}
}

void	inspect_newline(char *str)
{
	int		i;
	int		buff;
	char	*set;
	char	*trimmed_str;

	i = 0;
	set = " \t\n\v\f\r";
	ft_probel_newline(str);
	trimmed_str = ft_strtrim(str, set);
	if (!trimmed_str)
		exit(write(2, "ERROR!\n", 7));
	while (trimmed_str[i])
	{
		if (trimmed_str[i] == '\n')
		{
			buff = i;
			buff += 1;
			if (trimmed_str[buff] == ' ' || trimmed_str[buff] == '\t'
				|| trimmed_str[buff] == '\n')
				exit(write(1, "EER)\n", 5));
		}
		i++;
	}
	free(trimmed_str);
}
