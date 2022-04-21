SRCS	= main.c fractol_utils.c fractol.c key_hooks.c init_params.c

OBJS	= ${SRCS:.c=.o}

NAME	= fractol

MINILIB	= minilibx_macos/libmlx.a

PATHMLIB	= minilibx_macos/

PATHLIB	= libft/

LIBFT	= libft/libft.a

CC	= gcc

RM	= rm -f

CFLAGS	= -I. -Wall -Wextra -Werror -Imlx

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				@make -C ${PATHMLIB}
				@make -C ${PATHLIB}
				${CC} ${CFLAGS} ${MINILIB} ${LIBFT} ${OBJS} -lmlx -framework OpenGL -framework AppKit -L. -o ${NAME}

all:		${NAME}

clean:
				@make clean -C ${PATHLIB}
				${RM} ${OBJS}

fclean: 	clean
				@make clean
				${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re