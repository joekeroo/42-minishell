NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

MAIN = main.c
SRC = minishell.c get_next_line.c lexer/lexer.c lexer/lexer_utils.c
OBJ = ${SRC:.c=.o}

LIBFT_PATH = libft/
LIBFT = libft/libft.a

all: ${NAME}

${NAME}: ${OBJ} ${LIBFT}
	@${CC} ${CFLAGS} -o ${NAME} ${MAIN} ${OBJ} ${LIBFT}

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