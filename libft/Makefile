NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP
AR = ar
ARFLAGS = rcs

SRC_DIR = src
PRINTF_DIR = printf
GNL_DIR = get_next_line
OBJ_DIR = obj
INC_DIR = .

SRC_FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_putstr_fd.c ft_split.c ft_strchr.c ft_strcmp.c ft_strdup.c ft_striteri.c ft_strjoin.c \
	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
	ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strndup.c

PRINTF_FILES = ft_printf.c ft_printhex.c ft_printnbr.c ft_printchar.c
GNL_FILES = get_next_line.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES)) \
      $(addprefix $(PRINTF_DIR)/, $(PRINTF_FILES)) \
      $(addprefix $(GNL_DIR)/, $(GNL_FILES))

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
DEPS = $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

-include $(DEPS)

$(OBJ_DIR)/%.o: */%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR) -c $< -o $@


$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

a: all
c: clean
fc: fclean
