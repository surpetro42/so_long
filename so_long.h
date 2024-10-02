/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:37:28 by surpetro          #+#    #+#             */
/*   Updated: 2024/06/17 13:54:04 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_img
{
	void	*grass;
	void	*wall;
	void	*plaer;
	void	*mario;
	void	*exit_p;
	void	*opponent;
	void	*fanim;
	void	*marioanim;
}		t_img;

typedef struct s_game
{
	char	**s;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
	int		count_coins;
	int		count_step;
	int		pos_exit_x;
	int		pos_exit_y;
}		t_game;

typedef struct s_common
{
	t_point		points;
	t_img		imgs;
	t_game		game;
	void		*mlx_ptr;
	void		*win_ptr;
	int			count;
	int			i;
	int			l;
	int			ei;
	int			el;
	int			binary;
}		t_common;

/* ------------------------ utils ------------------------*/
char		*ft_itoa(int n);
int			ft_strcmp(char *s1, char *s2);
size_t		ft_strlen(char *s);
size_t		arrlen(char **s);
char		**ft_split(char *s, char c);
char		*ft_substr(char *s, size_t start, size_t len);
char		*ft_strtrim(char *s1, char *set);
char		**malloc_s(char **st);
char		*ft_strcpy(char *s1, char *s2);
char		**init(char **st);
char		*inspect_line(char *line, char *set);
void		free_buff_valid(char **s);
void		freearg(char **s);

/* ------------------------ valid ------------------------*/
t_point		position(char **s);
void		valid_gnl(int fd);
void		inspect_one(char **s);
void		inspect_len(char **s);
void		end_newline(char **s);
void		beginning_cep(char **s);
int			beginning_pe(char **s);
void		flood_fill(char **s);
void		check_from_flood(char **map);
void		inspect_newline(char *str);
void		ft_probel_newline(char *line);
void		validation_buff(char **buff_valid);

/* ------------------------ mlx_src ------------------------*/
void		window(char **s);
void		mlx_xpm_image(t_common *common);
void		mlx_xpm_game(t_common *common, void *win_ptr, char **s);
int			len_x(char **s);
int			len_y(char **s);
int			map_img(t_common *coomon);
void		w_up(t_common *common);
void		a_left(t_common *common);
void		s_down(t_common *common);
void		d_right(t_common *common);
void		fexit_plaer(t_common *common);
int			exitx(t_common *common);
void		steps(t_common *common);
void		animation_coin(t_common *common, char c, int v_a);

#endif
