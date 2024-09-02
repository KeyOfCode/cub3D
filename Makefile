################################################################################
#                                     CONFIG                                   #
################################################################################

NAME	:= cub3D
CC		:= gcc -g
RM 		:= rm -f
FLAGS	:= -Wall -Wextra -Werror
HEADERS	:= -I./include/ -I $(LIBMLX)/include
LIBMLX  := ./MLX42
MLX		:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBFT 	= 	libft/libft.a
FT		:= ./libft/libft.a -Llibft/ -lft

VALGRIND=	valgrind --leak-check=full --show-leak-kinds=all
VAL_FLAGS=	--child-silent-after-fork=yes \
			--read-inline-info=yes \
			--track-origins=yes --read-var-info=yes \
			--log-file=valgrind.rpt \
			./val

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRC_DIR		= src
SRCS_LIST	= main.c init.c hooks.c hook_utils.c player.c utils.c time.c\
				parsing.c parsing2.c parsing3.c sprites.c texture_utils.c\
				render/color.c render/raycast.c \
				render/render.c render/render_utils.c \
				render/textures.c \
				get_next_line.c
				# get_next_line_encheng.c
SRCS		= $(addprefix $(SRC_DIR)/, $(SRCS_LIST))
  
OBJS 		= $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} ${HEADERS} -c $< -o ${<:.c=.o}

TEST_TRGT	= maps/map2.cub

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED 		:= \033[1;31m
GREEN 		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

${NAME}:	${LIBFT} ${MLX} ${OBJS} 
	@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
	${CC} ${HEADERS} ${FLAGS} -o ${NAME} ${OBJS} ${FT} ${MLX} 
	@echo "$(GREEN)$(NAME) created ${CLR_RMV}✔️"

${MLX}:
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

${LIBFT}:
	@make -C libft all

all:		${NAME}

bonus:		all

clean:
	@ ${RM} *.o */*.o */*/*.o
	@rm -rf $(LIBMLX)/build
	@ ${RM} val
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
	@ ${RM} ${NAME}
	@make -C libft fclean
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re

exe:
	@make
	./$(NAME) $(TEST_TRGT)

val: $(OBJS) 
	@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}valgrind ${CLR_RMV}..."
	@${CC} ${HEADERS} ${FLAGS} -o val ${OBJS} ${MLX} -Llibft/ -lft
	$(VALGRIND) $(VAL_FLAGS) $(TEST_TRGT)

debug:	${OBJS} $(LIBFT) ${MLX}
	@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}debug ${CLR_RMV}..."
	@${CC} ${HEADERS} ${FLAGS} -g -o debug ${OBJS} ${MLX} -Llibft/ -lft
	@echo "$(GREEN)$(NAME) created ${CLR_RMV} ✔️"

push:
	./push.sh "push"
	