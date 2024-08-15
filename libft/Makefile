# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: darismen <darismen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 11:41:39 by darismen          #+#    #+#              #
#    Updated: 2024/08/15 13:09:42 by darismen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		libft.a

FILES=	ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c \
		ft_isupper.c ft_islower.c ft_strlen.c  ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_memmove.c ft_calloc.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
		ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
		ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_chrrmv.c\
		ft_itoa.c ft_strmapi.c ft_striteri.c ft_strndup.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_lstnew.c			\
				ft_lstadd_front.c	\
				ft_lstsize.c		\
				ft_lstlast.c		\
				ft_lstadd_back.c	\
				ft_lstclear.c		\
				ft_lstdelone.c		\
				ft_lstiter.c		\
				ft_lstmap.c			\
		ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_printf_util.c \
		ft_putnbr_base_fd.c \
		# get_next_line_encheng.c \
		# get_next_line.c gnl.c \


SRCS= $(addprefix src/, ${FILES})
#OBJS=	${SRCS:.c=.o}
OBJS=	$(addprefix objs/, ${FILES:.c=.o})
INC= includes/

CC=			gcc
RM=			rm -rf
AR=			ar -rcs
CFLAGS=		-Wall -Wextra -Werror -Iincludes/ 


all:	${NAME}

${NAME}: ${OBJS}
	@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
	@${AR} ${NAME} ${OBJS}
	@echo "$(GREEN)$(NAME) created ${CLR_RMV}✔️"

${OBJS}: ${SRCS}
	@$(CC) $(CFLAGS) -c $(SRCS)
	@rm -rf objs
	@mkdir objs
	@mv ${FILES:.c=.o} objs

#%.o: %.c
#	@$(CC) $(CFLAGS) -I/includes -c $< -o $@

clean:
	@${RM} objs
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
	@${RM} ${NAME}
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:		fclean ${NAME}

.PHONY:	all clean fclean re

CLR_RMV		:= \033[0m
RED 		:= \033[1;31m
GREEN 		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m