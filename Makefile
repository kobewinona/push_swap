NAME		= push_swap
CC			= gcc
CFLAGS		= -g -Wall -Wextra -Werror
ASAN_NAME	= push_swap_asan
ASAN_FLAGS	= -fsanitize=address
RM			= rm -rf
INCLUDES	= ./includes
LIBS_DIR	= ./libs
UTILS_DIR	= ./utils
LIBFTPRINTF	= -lftprintf
SRCS_DIR	= ./src
OBJS_DIR	= ./obj
SRCS 	= $(addprefix $(SRCS_DIR)/, main.c)
OBJS	= $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))

$(shell mkdir -p $(OBJS_DIR))

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBS_DIR) $(LIBFTPRINTF) -I$(INCLUDES)
	
asan: $(OBJS)
	cc $(ASAN_FLAGS) $(OBJS) -o $(ASAN_NAME) -L$(LIBS_DIR) $(LIBFTPRINTF) -I$(INCLUDES)

all: $(NAME) asan

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean: 
	$(RM) $(OBJS) $(OBJS_DIR)
	
fclean: clean
	$(RM) $(NAME) $(ASAN_NAME)

re: fclean all