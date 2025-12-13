NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I.

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX42_DIR = MLX42
MLX42_BUILD = $(MLX42_DIR)/build
MLX42_LIB = $(MLX42_BUILD)/libmlx42.a
MLX42_FLAGS = -I$(MLX42_DIR)/include -L$(MLX42_BUILD) -lmlx42 -lglfw -ldl -pthread -lm

SRCS = src/main.c \
       parse/first_check.c utils/utils.c parse/map_parse.c src/struct_init.c utils/map_utils.c parse/window_init.c \
	   textures.c
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(MLX42_LIB) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX42_LIB):
	@if [ ! -d "$(MLX42_BUILD)" ]; then \
		mkdir -p $(MLX42_BUILD); \
		cd $(MLX42_BUILD) && cmake ..; \
	fi
	make -C $(MLX42_BUILD)

$(NAME): $(OBJS) $(LIBFT) $(MLX42_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX42_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	rm -rf $(MLX42_BUILD)

re: fclean all

.PHONY: all clean fclean re
.PHONY: all clean fclean re
