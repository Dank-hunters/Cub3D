SRCS        = parse/gnl.c \
			  parse/parse.c \
			  parse/parse_pt2.c \
			  parse/parse_map.c \
			  parse/parse_texture_path.c \
			  parse/parse_utils.c \
			  parse/utils.c \
			  parse/utils_to_map.c \
			  parse/minolib.c \
			  parse/utils_to_map2.c \
			  main.c \
			  graph/utils_to_mlx.c \
			  graph/get_rgb.c \
			  graph/get_infos.c \
			  graph/init_first_img.c \
			  graph/event.c \
			  graph/texture.c \

HEADERS        = cub3d.h

#
#LIBFTA        = LIBFT/libft.a

MLXA        = MLX/libmlx.a

NAME        = cub3d

CFLAGS        =  -Wall -Wextra -Werror  -I MLX -Ofast -march=native 

CC            = gcc $(CFLAGS)

RM            = rm -f

all:        $(NAME)

#mklibfta:
#$(MAKE) -C LIBFT

cub:        $(SRCS) $(LIBFTA)
			$(CC) $? -L MLX -l MLX -framework OpenGL -framework 			AppKit -o $(NAME)

$(NAME):    cub

clean:
	$(RM)

fclean:        clean
	$(RM) $(NAME)

re:            fclean all

.PHONY:       cub all clean fclean re
