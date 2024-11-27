# Variables
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
NAME    = libft.a

SRC_DIR = .
SRC     = ft_atoi.c ft_bzero.c ft_calloc.c ft_isascii.c ft_isalnum.c ft_isalpha.c \
          ft_isdigit.c ft_isprint.c ft_itoa.c ft_memcpy.c ft_memmove.c ft_memset.c \
          ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
          ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
          ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
          ft_substr.c ft_tolower.c ft_toupper.c ft_memchr.c ft_memcmp.c ft_read_aloc.c

BONUS_DIR = .
SRC_B   = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
          ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

GNL_DIR = gnl
GNL_SRC = get_next_line_bonus.c

OBJ     = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))
OBJ_B   = $(addprefix $(BONUS_DIR)/, $(SRC_B:.c=.o))
GNL_OBJ = $(addprefix $(GNL_DIR)/, $(GNL_SRC:.c=.o))

HEADER  = libft.h $(GNL_DIR)/get_next_line_bonus.h

# Couleurs
RED     = \033[0;31m
YELLOW  = \033[0;33m
GREEN   = \033[0;32m
NC      = \033[0m

# Règles de compilation
all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo -e "$(GREEN)Static library created: $(NAME)$(NC)"

%.o: %.c $(HEADER)
	@printf "$(YELLOW)Generating libft object... %-38.38s \r$(NC)" $@
	$(CC) $(CFLAGS) -c $< -o $@

so: $(OBJ)
	@echo "Creating dynamic library libft.so..."
	$(CC) -nostartfiles -shared -o libft.so $(OBJ)

libft.so: so

bonus: $(OBJ) $(OBJ_B) $(GNL_OBJ)
	@ar rc $(NAME) $(OBJ) $(OBJ_B) $(GNL_OBJ)
	@ranlib $(NAME)
	@echo "$(GREEN)Bonus added!$(NC)"

verbose: $(NAME)
	@echo "$(GREEN)Compiling directories:$(NC)"
	@$(foreach dir, $(SRC_DIR) $(BONUS_DIR) $(GNL_DIR), \
		echo "$(YELLOW)Compiling directory: $(dir)$(NC)"; \
		$(MAKE) --no-print-directory all -C $(dir);)

clean:
	@echo "$(RED)Removing object files...$(NC)"
	@rm -rf $(OBJ) $(OBJ_B) $(GNL_OBJ)

fclean: clean
	@echo "$(RED)Removing all generated files...$(NC)"
	@rm -f $(NAME) libft.so

re: fclean all

.PHONY: all clean fclean re bonus so verbose
