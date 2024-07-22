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
HEADERS	:= -MMD -MP -I libft/includes -I $(LIBMLX)/include/ -I include


LIBFT = libft/libft.a
LIBMLX := ./MLX42
MLX = $(LIBMLX)/build/libmlx42.a
LIBFLAGS = -L libft -L MLX42/build -lft -ldl -lglfw -pthread -lm
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRC_DIR		= src
OBJ_DIR		= obj

SRCS_LIST	= main.c init.c hooks.c player.c utils.c \
				parsing.c parsing2.c
SRCS		= $(addprefix $(SRC_DIR)/, $(SRCS_LIST))

TEST_LIST	= main.c init.c hooks.c player.c utils.c \
			core/draw.c core/sprites.c core/utils.c \
			parsing/parsing1.c parsing/parsing2.c parsing/parsing3.c
TEST		= $(addprefix $(SRC_DIR)/, $(TEST_LIST))
						  
OBJS 	:= $(SRCS:.c=.o)

TEST_OBJS 	:= $(TEST:.c=.o)

%.o: %.c 
	${CC} ${FLAGS} $(HEADERS) $< -o $@ $(LIBFLAGS)

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

all: $(LIBFT) mlx ${NAME}

${NAME}: ${OBJS}
	@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
	${CC} ${FLAGS} $(HEADERS) -o ${NAME} ${OBJS} $(MLX) $(LIBFLAGS)
	@echo "$(GREEN)$(NAME) created ${CLR_RMV}✔️"


$(LIBFT):
	@make -C libft/ all

mlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

bonus:		all

-include $(DEPS)

clean:
			@ ${RM} *.o */*.o */*/*.o
			@rm -rf $(LIBMLX)/build
			@make -C libft/ clean
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@make -C libft/ fclean
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

test:	${OBJS} $(LIBFT) $(MLX)
	@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}test ${CLR_RMV}..."
	${CC} ${FLAGS} -o test ${OBJS}
	@echo "$(GREEN)$(NAME) created ${CLR_RMV} ✔️"

