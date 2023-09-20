SRCS = main.c init.c free.c path_ctl.c map_ctl.c gnl/get_next_line.c gnl/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)
CC = gcc
MFLAGS = ./mlxlib/libmlx.a
LFLAGS = ./libft/libft.a
AFLAGS =  -Wall -Wextra -Werror -I./mlxlib -I./libft
RM = rm -rf
NAME = cub3D

all :$(MFLAGS) $(LFLAGS) $(NAME)

$(MFLAGS):
	make -C ./mlxlib

$(LFLAGS):
	make -C ./libft

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MFLAGS) $(LFLAGS) $(AFLAGS) -framework OpenGL -framework AppKit -o $(NAME)

fclean : clean
	make fclean -C ./libft
	$(RM) $(NAME)

clean :
	make clean -C ./mlxlib
	make clean -C ./libft
	$(RM) ./*.o ./gnl/*.o

re : fclean all

.PHONY : all fclean clean re
