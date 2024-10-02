/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_buff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:10:38 by surpetro          #+#    #+#             */
/*   Updated: 2024/06/11 15:42:44 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*inspect_line(char *line, char *set)
{
	inspect_newline(line);
	ft_probel_newline(line);
	line = ft_strtrim(line, set);
	return (line);
}

void	validation_buff(char **buff_valid)
{
	inspect_len(buff_valid);
	inspect_one(buff_valid);
	beginning_cep(buff_valid);
}
