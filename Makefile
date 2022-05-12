NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L/usr/include -lreadline
RM = rm -f

MAIN = main.c
SRC = minishell.c \
	  utilities/get_next_line.c utilities/array_utils.c \
	  lexer/lexer.c lexer/lexer_utils.c
OBJ = ${SRC:.c=.o}

LIBFT_PATH = libft/
LIBFT = libft/libft.a

all: ${NAME}

${NAME}: ${OBJ} ${LIBFT}
	@${CC} ${CFLAGS} ${LDFLAGS} -o ${NAME} ${MAIN} ${OBJ} ${LIBFT}

${LIBFT}:
	@make re -C ${LIBFT_PATH}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@${RM} ${OBJ}
	@make clean -C ${LIBFT_PATH}

fclean: clean
	@${RM} ${NAME}
	@make fclean -C ${LIBFT_PATH}

re: fclean all

.PHONY = all clean fclean re