NAME		= minishell
CC		= gcc
CFLAGS		= -Wall -Wextra -Werror -g

SRCS		= main.c \
		  args_and_env/environment.c \
		  args_and_env/environment_utils.c \
		  builtins/env.c \
		  builtins/export.c \
		  builtins/export_utils.c \
		  builtins/echo.c \
		  builtins/pwd.c \
		  builtins/exit.c \
		  builtins/cd.c \
		  builtins/builtins_utils.c \
		  builtins/unset.c \
		  loop/logo.c \
		  executor/executor.c \
		  executor/single.c \
		  executor/pipe.c \
		  executor/pipe_utils.c \
		  executor/path.c \
		  executor/path_utils.c \
		  executor/redir.c \
		  executor/heredoc.c \
		  executor/builtin.c \
		  executor/utils.c \
		  executor/free.c \
		  executor/signals.c \
		  parser/expander.c \
		  parser/expander_utils.c \
		  parser/lexer.c \
		  parser/lexer_utils.c \
		  parser/lexer_word.c \
		  parser/parser.c \
		  parser/parser_args.c \
		  parser/parser_cmd.c \
		  parser/parser_utils.c

OBJS		= $(SRCS:.c=.o)

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

INCLUDES	= -I. -I$(LIBFT_DIR) -Iargs_and_env -Ibuiltins \
		  -Iloop -Iexecutor -Iparser

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -lreadline -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
