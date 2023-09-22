# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 13:56:12 by nibernar          #+#    #+#              #
#    Updated: 2023/09/18 11:37:20 by nibernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########################
#		MAKEFILE		#
#########################

NAME		=	philo

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
				src/print.c\
				src/check_situation.c\


OBJS		=	${SRCS:.c=.o}

#########################
# 	COMPILER OPTIONS	#
#########################

CFLAG		=	-Wall -Wextra -Werror
CC			=	cc

#########################
# 		RULES			#
#########################
all: $(NAME)

./src/%.o: ./src/%.c ${HEADERS}
	${CC} ${CFLAGS} -I${HEADER_PATH} -g -c $< -o $@
	
${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} -pthread

#########################
# 	CLEAN COMMANDS		#
#########################

force :

lib: force
	@make -sC $(LIBFT_PATH)

clean :
	@echo "Delete *.o"
	${RM} ${OBJS} 
	@echo "Succes !"

fclean: clean
	@echo "Delete *.a && executable"
	${RM} ${NAME}
	@echo "Succes !"

re : fclean all

.PHONY: all clean fclean re force

