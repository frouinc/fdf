# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 15:07:13 by cyrillef          #+#    #+#              #
#    Updated: 2018/01/19 16:53:34 by cyrillefrouin    ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC					=	gcc

NAME				=	fdf

SRCS_DIR			=	srcs/

SRCS				=	main.c \
						free_memory.c \
						init.c \
						read_file.c \
						display.c \
						draw.c \
						coordinates.c \
						keys.c \
						keys_misc.c \
						keys_move.c \
						keys_rotate.c \
						keys_zoom.c

SRCS_FULL			=	$(addprefix $(SRCS_DIR), $(SRCS))

OBJS				=	$(SRCS_FULL:.c=.o)

CFLAGS				=	-Wall -Wextra -I./includes/

all:				mlx libft $(NAME)

%.o : %.c
					@gcc -g -o $@ -c $< $(CFLAGS)
					@echo "\033[K\033[34mFdf :\033[0m [ Compiling :\033[33m $^\033[0m]\033[1A"

$(NAME):			$(OBJS)
					@$(GCC) $(OBJS) -o $(NAME) -L./libs/libft -lft -L./libs/mlx -lmlx -framework OpenGL -framework AppKit -fsanitize=address
					@echo "\033[K\033[32m=============FDF================\033[0m"
					@echo "\033[34mCompiling\033[0m" [ $(NAME) ] "\033[K\033[32mSuccessful\033[00m"
					@echo "\033[32m================================\033[00m"

libft:
					@make -C libs/libft

mlx:
					@make -C libs/mlx

clean:
					@rm -f $(OBJS)
					@echo "\033[K\033[31m=============FDF=============\033[0m"
					@echo "\033[31mCleaning\033[00m  " [ "*.o" ] "  \033[32mComplete\033[00m"
					@echo "\033[K\033[31m=============================\033[0m"
					@make -C libs/libft clean
					@make -C libs/mlx clean

rclean:
					@rm -f $(OBJS)
					@echo "\033[K\033[31m=============FDF=============\033[0m"
					@echo "\033[31mCleaning\033[00m  " [ "*.o" ] "  \033[32mComplete\033[00m"
					@echo "\033[K\033[31m=============================\033[0m"

fclean:				clean
					@rm -f $(NAME)
					@echo "\033[K\033[31m=============FDF=============\033[0m"
					@echo "\033[31mRemoving\033[00m  " [ "fdf" ] "  \033[32mComplete\033[00m"
					@echo "\033[K\033[31m=============================\033[0m"
					@make -C libs/libft fclean

rfclean:			rclean
					@rm -f $(NAME)
					@echo "\033[K\033[31m===========COREWAR===========\033[0m"
					@echo "\033[31mRemoving\033[00m  " [ "fdf" ] "  \033[32mComplete\033[00m"
					@echo "\033[K\033[31m=============================\033[0m"

re:					fclean all

ren:				rfclean all

.PHONY:				all clean fclean re ren
