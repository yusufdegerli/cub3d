SRCS = main.c init.c free.c path_ctl.c player_ctl.c gnl/get_next_line/get_next_line.c gnl/get_next_line/get_next_line_utils.c \
		putting_pxls_to_img.c math.c move.c move2.c draw.c key_press.c path_ctl2.c set_user.c \
		math2.c init2.c

OBJS = $(SRCS:.c=.o)
CC = gcc
MFLAGS = ./minilibx-linux/libmlx.a
LFLAGS = ./libft/libft.a
CFLAGS =  -Wall -Wextra -Werror -I./minilibx-linux -I./libft
RM = rm -rf
NAME = cub3D

all :$(MFLAGS) $(LFLAGS) $(NAME)

$(MFLAGS):
	make -C ./minilibx-linux

$(LFLAGS):
	make -C ./libft

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MFLAGS) $(LFLAGS) $(CFLAGS) -lXext -lX11 -lm -lz -o $(NAME)

fclean : clean
	make fclean -C ./libft
	$(RM) $(NAME)

clean :
	make clean -C ./minilibx-linux
	make clean -C ./libft
	$(RM) ./*.o ./gnl/*.o

re : fclean all

.PHONY : all fclean clean re
