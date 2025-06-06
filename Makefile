CC		:= cc
CFLAGS	:= -Wall -Ofast
MLX_DIR		:= ./lib/MLX42
MLX		:= $(MLX_DIR)/build/libmlx42.a
LIBFT_DIR	:= ./lib/libft
LIBFT 	:= $(LIBFT_DIR)/libft.a
HEADERS	:= -I ./includes -I $(MLX_DIR)/include/MLX42 -I $(LIBFT)
UNAME_S	:= $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LIBS	:= -L$(LIBFT_DIR) -lft $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm
endif
ifeq ($(UNAME_S),Darwin)
	LIBS	:= -L$(LIBFT_DIR) -lft $(MLX_DIR)/build/libmlx42.a \
	-Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/" -pthread -lm
endif
SRC_DIR	:= sources
SRC		:= main.c \
			init.c \
			validation.c \
			map.c \
			read_param.c \
			load_param.c \
			player.c \
			utils.c \
			draws.c \
			ray_casting.c \
			utils_ray.c \
			finish.c
SRCS	:= $(addprefix $(SRC_DIR)/, $(SRC))
OBJ_DIR	:= obj
OBJ		:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
NAME	:= cub3d

all: $(NAME)

$(MLX): $(MLX_DIR)
	cmake $(MLX_DIR) -B $(MLX_DIR)/build;
	make -C$(MLX_DIR)/build -j4;

$(LIBFT): $(LIBFT_DIR)
	make -C$(LIBFT_DIR);

$(MLX_DIR):
	git clone https://github.com/codam-coding-college/MLX42.git $@;

$(LIBFT_DIR):
	lib/libft $@;

$(OBJ_DIR):
	mkdir obj

$(NAME): $(MLX) $(LIBFT) $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) $(LIBS) $(HEADERS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c includes/cub3d.h
	$(CC) -c $(CFLAGS) $< -o $@ $(HEADERS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm $(NAME)
	rmdir $(OBJ_DIR)
	rm -rf $(MLX_DIR)

re: fclean all

.PHONY: all, clean, fclean, re
