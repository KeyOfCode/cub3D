################################################################################
#                                     CONFIG                                   #
################################################################################

NAME	:= cub3D
CC		:= gcc
FLAGS	:= -Wall -Wextra -Werror 
HEADERS	:= -I./include/ -I $(LIBMLX)/include
LIBMLX  := ./MLX42
MLX		:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRC_DIR		= src
SRCS_LIST	= main.c init.c hooks.c player.c utils.c \
				parsing.c parsing2.c sprites.c draw.c
SRCS		= $(addprefix $(SRC_DIR)/, $(SRCS_LIST))
	  
OBJS 	:= $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} ${HEADERS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################

${NAME}:	${OBJS} ${LIBFT} ${MLX}
	@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
	@${CC} ${HEADERS} ${FLAGS} -o ${NAME} ${OBJS} ${MLX} -Llibft/ -lft
	@echo "$(GREEN)$(NAME) created ${CLR_RMV}✔️"

${MLX}:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

${LIBFT}:
	@$(MAKE) -C $(LIBFT)

${MLX}:
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

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

debug:	${OBJS} ${LIBFT} ${MLX}
	@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}debug ${CLR_RMV}..."
	@${CC} ${HEADERS} ${FLAGS} -g -o debug ${OBJS} ${MLX} -Llibft/ -lft
	@echo "$(GREEN)$(NAME) created ${CLR_RMV} ✔️"


CLR_RMV		:= \033[0m
RED 		:= \033[1;31m
GREEN 		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM 			:= rm -f
