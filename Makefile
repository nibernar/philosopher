# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 13:56:12 by nibernar          #+#    #+#              #
#    Updated: 2023/09/04 14:14:00 by nicolasbern      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########################
#		MAKEFILE		#
#########################

NAME		=	philosopher

#########################
#	HEADER FOLDERS		#
#########################

HEADER_PATH	= ./include/
HEADER_FILES = philosopher.h
HEADERS = $(addprefix $(HEADER_PATH), $(HEADER_FILES))

#########################
#	FOLDERS AND NAMES	#
#########################

SRCS		=	src/philosopher.c\
				src/parsing.c\
				src/routine.c\
				src/utils.c\
				src/utils2.c\
				src/print_struct.c\


OBJS		=	${SRCS:.c=.o}

#########################
# 	COMPILER OPTIONS	#
#########################

CFLAG		=	-Wall -Wextra -Werror
CC			=	cc

#########################
# 		RULES			#
#########################

./src/%.o: ./src/%.c ${HEADERS}
	${CC} ${CFLAGS} -I${HEADER_PATH} -g -c $< -o $@
	
${NAME} : ${OBJS}
	echo "Compiling: philosopher..."
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	echo "Succes !\n"

#########################
# 	CLEAN COMMANDS		#
#########################

force :

lib: force
	@make -sC $(LIBFT_PATH)

clean :
	@echo "Delete *.o"
	${RM} ${OBJS} 
	@echo "Succes !\n"

fclean: clean
	@echo "Delete *.a && executable"
	${RM} ${NAME}
	@echo "Succes !\n"

re : fclean all

.PHONY: all clean fclean re force

