# Variables
CC          = cc
CFLAGS      = -g -Wall -Wextra -Werror  -o my_project
NAME        = my_project
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a
MLX_DIR     = mlx_linux
MLX_LIB     = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm
INCLUDES    = -I includes -I $(LIBFT_DIR) -I $(MLX_DIR)
SRC_DIR     = src
OBJ_DIR     = obj
SRC         = main.c read.c utils.c error.c parsing.c draw.c event.c project.c init.c
OBJ         = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Couleurs
RED         = \033[0;31m
YELLOW      = \033[0;33m
GREEN       = \033[0;32m
NC          = \033[0m

# Règles
all: $(OBJ_DIR) $(LIBFT) $(MLX_LIB) $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)Linking project executable: $(NAME)...$(NC)"
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created successfully!$(NC)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling $< into $@...$(NC)"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo "$(YELLOW)Building libft library...$(NC)"
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	@echo "$(YELLOW)Building minilibx library...$(NC)"
	@$(MAKE) -C $(MLX_DIR)

clean:
	@echo "$(RED)Removing project object files...$(NC)"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@echo "$(RED)Removing $(NAME), libft, and minilibx files...$(NC)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re

