NAME    = so_long
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g3 -fsanitize=address
SRCS    = so_long.c \
          validation/inspect_cep.c \
          validation/inspect_fill.c \
          validation/inspect_len.c \
          validation/inspect_newline.c \
          validation/validation_buff.c \
          validation/inspect_one.c \
          utils/ft_itoa.c \
          utils/initialization.c \
          utils/malloc_s.c \
          utils/ft_strcpy.c \
          utils/split.c \
          utils/ft_strcmp.c \
          utils/ft_strtrim.c \
          utils/utils.c \
          utils/free_arg.c \
          get_next_line/get_next_line_utils.c \
          get_next_line/get_next_line.c \
          mlx_src/card_size.c \
          mlx_src/exit.c \
          mlx_src/exitx.c \
          mlx_src/steps.c \
          mlx_src/map_img_anim.c \
          mlx_src/map_img.c \
          mlx_src/utils.c \
          mlx_src/movement.c \
          mlx_src/window.c 

OBJS    = $(SRCS:.c=.o)

MLX     = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

%.o: %.c Makefile 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
