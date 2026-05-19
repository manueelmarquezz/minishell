NAME            = minishell
CC              = gcc
CFLAGS          = -Wall -Wextra -Werror -g

SRCS            = main.c \
                  src/args_and_env/environment.c \
                  src/args_and_env/environment_utils.c \
                  src/builtins/env.c \
                  src/builtins/export.c \
                  src/builtins/export_utils.c \
                  src/builtins/echo.c \
                  src/builtins/pwd.c \
                  src/builtins/exit.c \
                  src/builtins/cd.c \
                  src/builtins/builtins_utils.c \
                  src/builtins/unset.c \
                  src/executor/executor.c \
                  src/executor/single.c \
                  src/executor/pipe.c \
                  src/executor/pipe_utils.c \
                  src/executor/path.c \
                  src/executor/path_utils.c \
                  src/executor/redir.c \
                  src/executor/heredoc.c \
                  src/executor/heredoc_utils.c \
                  src/executor/builtin.c \
                  src/executor/utils.c \
                  src/executor/free.c \
                  src/executor/signals.c \
                  src/parser/expander.c \
                  src/parser/expander_utils.c \
                  src/parser/lexer.c \
                  src/parser/lexer_utils.c \
                  src/parser/lexer_word.c \
                  src/parser/parser.c \
                  src/parser/parser_args.c \
                  src/parser/parser_cmd.c \
                  src/parser/parser_utils.c

OBJS            = $(SRCS:.c=.o)

LIBFT_DIR       = libft
LIBFT           = $(LIBFT_DIR)/libft.a

INCLUDES        = -I. -I$(LIBFT_DIR) -Isrc/args_and_env -Isrc/builtins \
                  -Isrc/executor -Isrc/parser

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
