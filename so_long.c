/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:37:22 by surpetro          #+#    #+#             */
/*   Updated: 2024/06/11 16:00:06 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*gnl(int fd)
{
	char	*str;
	char	*line;

	line = NULL;
	str = NULL;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
		{
			free(str);
			break ;
		}
		line = ft_strjoin(line, str);
		free(str);
	}
	return (line);
}

char	**trim_line(char **st, char *set)
{
	int		i;
	char	**s;

	i = 0;
	s = NULL;
	while (st[i])
		i++;
	s = (char **)malloc(sizeof(char *) * (i + 1));
	if (!s)
		exit(write(2, "ERROR MALLOC\n", 13));
	i = 0;
	while (st[i])
	{
		s[i] = ft_strtrim(st[i], set);
		i++;
	}
	s[i] = NULL;
	return (s);
}

void	validation(char *line, char *set)
{
	char	**st;
	char	**buff_valid;
	char	**s;
	char	*tmp;

	st = NULL;
	buff_valid = NULL;
	s = NULL;
	tmp = inspect_line(line, set);
	st = ft_split(tmp, '\n');
	free(tmp);
	free(line);
	if (!st)
		freearg(st);
	buff_valid = trim_line(st, set);
	free_buff_valid(st);
	validation_buff(buff_valid);
	s = init(buff_valid);
	if (!s)
		freearg(s);
	flood_fill(buff_valid);
	free_buff_valid(buff_valid);
	window(s);
}

void	valid_gnl(int fd)
{
	int		i;
	char	*set;
	char	*line;

	i = 0;
	set = "\t\n\v\f\r ";
	line = NULL;
	line = gnl(fd);
	if (!line)
		exit(write(2, "ERROR\nThere is nothing in the file\n", 36));
	validation(line, set);
}

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	size_t	len;

	i = 0;
	len = ft_strlen(argv[1]);
	if (argc > 1)
	{
		fd = -1;
		if (len > 4 && ft_strcmp(&argv[1][len - 4], ".ber") == 0)
		{
			fd = open(argv[1], O_RDWR);
			if (fd <= 0)
				return (1);
			valid_gnl(fd);
		}
		if (fd < 0)
			return (1);
		i++;
	}
	else
		return (write(2, "DATARKA\n", 8));
	return (0);
}
