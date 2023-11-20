NAME		= push_swap
ASAN_NAME	= push_swap_asan

CC			= gcc
# CFLAGS		= -g -Wall -Wextra -Werror
CFLAGS		= -g
ASAN_FLAGS	= -fsanitize=address
RM			= rm -rf
INCLUDES	= ./includes
LIBFTPRINTF	= -lftprintf

SRCS_DIR	= ./src
OBJS_DIR	= ./obj
LIBS_DIR	= ./libs
UTILS_DIR	= ./utils

SRCS 		= $(addprefix $(SRCS_DIR)/, main.c parse_argv.c is_argv_valid.c \
			handle_error.c fill_stack.c is_stack_sorted.c \
			swap.c push.c rotate.c reverse_rotate.c \
			sort_small.c sort_big.c)
UTILS_SRCS	= $(addprefix $(UTILS_DIR)/, print_err_msg.c print_stack.c \
			free_double_arr.c \
			init_stack.c stackadd_front.c free_stack.c \
			init_chunk.c \
			find_stack_min.c find_stack_max.c)
OBJS		= $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))
OBJS		+= $(patsubst $(UTILS_DIR)/%.c,$(OBJS_DIR)/%.o,$(UTILS_SRCS))

$(NAME): $(OBJS) $(INCLUDES)/push_swap.h
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBS_DIR) $(LIBFTPRINTF) -I$(INCLUDES)

asan: $(OBJS)
	cc $(ASAN_FLAGS) $(OBJS) -o $(ASAN_NAME) -L$(LIBS_DIR) $(LIBFTPRINTF) -I$(INCLUDES)

all: $(NAME) asan

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

$(OBJS_DIR)/%.o: $(UTILS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean: 
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME) $(ASAN_NAME)

re: fclean all