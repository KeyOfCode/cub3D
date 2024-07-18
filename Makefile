#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME	:= cub3D
CC		:= gcc
FLAGS	:= -Wall -Wextra -Werror 
HEADERS	:= -I./include/ -I MLX42/include/MLX42 -lglfw \
		   -ldl -lglfw -pthread -lm -Llibft/ -lft
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS 	:= src/main.c \
						  
OBJS 	:= $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} ${HEADERS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED 		:= \033[1;31m
GREEN 		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM 			:= rm -f

${NAME}:	${OBJS} ${LIBFT}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${HEADERS} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created ${CLR_RMV}✔️"

${LIBFT}:
	@$(MAKE) -C $(LIBFT)

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re

exe:
	@make
	./$(NAME)

val: $(OBJS) 
	$(CC) $(FLAGS) -o val $(OBJS)
	$(VALGRIND)  $(VAL_FLAGS)

debug:	${OBJS}
	@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}debug ${CLR_RMV}..."
	${CC} ${FLAGS} -g -o debug ${OBJS}
	@echo "$(GREEN)$(NAME) created ${CLR_RMV} ✔️"

