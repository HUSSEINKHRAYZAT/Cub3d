CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -I Include
MLX_FLAGS	= -L ./minilibx-linux -lmlx -lXext -lX11 -lm
SRCDIR  = Srcs
OBJDIR  = Obj
INCDIR  = Include

NAME    = cub3d

# Manually listing all source files
SRCS    = \
	Srcs/Game/clearing.c \
	Srcs/Game/drawing.c \
	Srcs/Game/drawingextra.c \
	Srcs/Game/moving.c \
	Srcs/Game/player.c \
	Srcs/Game/playerdir.c \
	Srcs/Game/raycasting.c \
	Srcs/Game/raycast2.c \
	Srcs/Game/raycast3.c \
	Srcs/Game/raycast4.c \
	Srcs/Game/interaction.c \
	Srcs/Utils/ft_split.c \
	Srcs/Utils/libft_utils1.c \
	Srcs/Utils/libft_utils2.c \
	Srcs/Utils/libft_utils3.c \
	Srcs/Utils/libft_utils4.c \
	Srcs/Utils/libft_utils5.c \
	Srcs/Validation/check.c \
	Srcs/Validation/check2.c \
	Srcs/Validation/clean.c \
	Srcs/Validation/cleanup.c \
	Srcs/Validation/file.c \
	Srcs/Validation/tools.c \
	Srcs/Validation/tools_dir.c \
	Srcs/Validation/valid.c \
	Srcs/main.c

# Convert source file paths to object file paths
OBJS    = $(SRCS:Srcs/%.c=Obj/%.o)

GREEN   = \033[0;32m
RED     = \033[0;31m
RESET   = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME) $(LDFLAGS)
	@echo "$(RED)✔ Cub3d Compiled!$(RESET)"

# Create object files, ensuring the subdirectories exist
Obj/%.o: Srcs/%.c | create_obj_dirs
	@$(CC) $(CFLAGS) -c $< -o $@

# Ensure necessary object subdirectories exist
create_obj_dirs:
	@mkdir -p $(OBJDIR)/Game
	@mkdir -p $(OBJDIR)/Utils
	@mkdir -p $(OBJDIR)/Validation

clean:
	@rm -rf $(OBJDIR)
	@echo "$(RED)🗑️  Object files removed!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)🗑️  Executable removed!$(RESET)"

re: fclean all

v: all
	@echo "$(RED)Compiling with Valgrind...$(RESET)"
	@valgrind --leak-check=full -q ./$(NAME)

.PHONY: all clean fclean re v
