/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:10:38 by surpetro          #+#    #+#             */
/*   Updated: 2024/06/02 16:57:49 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**init(char **st)
{
	int		i;
	int		l;
	char	**s;

	i = 0;
	s = NULL;
	while (st[i])
		i++;
	s = (char **)malloc((i + 1) * sizeof(char *));
	if (!s)
		return (NULL);
	i = 0;
	while (st[i])
	{
		l = ft_strlen(st[i]);
		s[i] = (char *)malloc((l + 1) * sizeof(char));
		if (!s[i])
			return (NULL);
		ft_strcpy(s[i], st[i]);
		i++;
	}
	s[i] = NULL;
	return (s);
}
