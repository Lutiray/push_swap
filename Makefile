NAME = push_swap

# Компилятор и флаги (строго по правилам Школы 42)
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Директории
SRC_DIR = src
CMD_DIR = src/commands
LIBFT_DIR = libft

# Библиотека libft
LIBFT = $(LIBFT_DIR)/libft.a

# Исходные файлы (.c)
SRCS = main.c \
       $(SRC_DIR)/init_stack.c \
       $(SRC_DIR)/push_swap.c \
       $(SRC_DIR)/utils.c \
       $(CMD_DIR)/pa_pb.c \
       $(CMD_DIR)/ra_rb_rr.c \
       $(CMD_DIR)/rra_rrb_rrr.c \
       $(CMD_DIR)/sa_sb_ss.c

# Объектные файлы (.o)
OBJS = $(SRCS:.c=.o)

# Флаги для поиска заголовочных файлов (.h)
# Позволяет писать #include "push_swap.h" и #include "libft.h" без указания папок
INCLUDES = -I $(SRC_DIR) -I $(LIBFT_DIR)

# Команда удаления
RM = rm -f

# ----------------- ПРАВИЛА -----------------

# Главное правило
all: $(LIBFT) $(NAME)

# Правило сборки библиотеки libft
# Заходит в папку libft и запускает тамошний Makefile
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Правило сборки самой программы push_swap
# Линкует наши объектные файлы вместе с библиотекой libft
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

# Правило превращения .c в .o
# Зависит также от push_swap.h, чтобы при изменении хедера файлы пересобирались
%.o: %.c $(SRC_DIR)/push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Очистка объектных файлов (.o) в нашем проекте и внутри libft
clean:
	$(RM) $(OBJS)
	@make clean -C $(LIBFT_DIR)

# Полная очистка, включая экзешник и libft.a
fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)

# Пересборка с нуля
re: fclean all

# Указываем, что это команды, а не файлы
.PHONY: all clean fclean re