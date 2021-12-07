NAME        = cub3D

SRCS        = parse/get_next_line.c \
	          parse/get_next_line_utils.c \
			  parse/map_parsing.c \
			  parse/map_parsing2.c \
			  parse/parse.c \
			  parse/parse_keys.c \
			  parse/parse_pt2.c \
			  parse/parse_texture_path.c \
			  parse/utils.c \
			  parse/utils_to_map.c \
			  parse/minolib.c \
			  graph/main.c \
			  graph/utils_to_mlx.c \
			  graph/utils_to_graph.c \
			  graph/get_infos.c \
			  graph/init_first_img.c \
			  graph/event.c \
			  graph/texture.c \


OBJS		=	$(SRCS:%.c=%.o)

INC_DIR			= include

INC			= $(INC_DIR)/cub3d.h

MLX			= dependency/mlx/libmlx.a

FRAMEWORK	 = -framework OpenGL -framework Appkit
.SILENT: 

CFLAGS		=  -Wall -Wextra -Werror -I $(INC_DIR)

CC			= gcc

all:        $(NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@ 


$(NAME) : 	$(MLX) $(OBJS)
			$(CC) $(CFLAGS) $(FRAMEWORK) $(OBJS) $(MLX) -o $(NAME)
			printf "Compilation completed"

$(MLX):
			$(MAKE) -C dependency/mlx


clean:
			rm -f $(OBJS)
			$(MAKE)	-C dependency/mlx clean

fclean:        clean
	$(RM) $(NAME)

re:            fclean all

.PHONY:       all clean fclean re
