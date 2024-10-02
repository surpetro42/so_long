/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:10:38 by surpetro          #+#    #+#             */
/*   Updated: 2024/06/01 22:03:15 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**malloc_s(char **st)
{
	int		i;
	char	**s;

	i = 0;
	while (st[i])
		i++;
	s = (char **)malloc(sizeof(char *) * (i + 1));
	if (!s)
		exit(write(2, "ERROR MALLOC\n", 13));
	return (s);
}
