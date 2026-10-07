NAME		= fdf

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -std=gnu17 -MMD -MP

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= includes
LIBFT_DIR	= libft
MLX_DIR		= mlx_linux

LIBFT		= $(LIBFT_DIR)/libft.a
MLX			= $(MLX_DIR)/libmlx.a

INCLUDES	= -I $(INC_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR)
LDFLAGS		= -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC			= main.c \
			  map_read.c \
			  map_parse.c \
			  map_utils.c \
			  view.c \
			  transform.c \
			  draw.c \
			  line.c \
			  hud.c \
			  events.c \
			  actions.c \
			  exit.c
OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEP			= $(OBJ:.o=.d)

GREEN		= \033[0;32m
YELLOW		= \033[0;33m
RED			= \033[0;31m
NC			= \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@
	@printf "$(GREEN)$(NAME) ready$(NC)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@printf "$(YELLOW)Compiling $<$(NC)\n"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

$(MLX):
	@printf "$(YELLOW)Building minilibx$(NC)\n"
	@$(MAKE) -s -C $(MLX_DIR) > /dev/null 2>&1

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(MLX_DIR) clean > /dev/null 2>&1
	@printf "$(RED)Objects removed$(NC)\n"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@printf "$(RED)$(NAME) removed$(NC)\n"

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
