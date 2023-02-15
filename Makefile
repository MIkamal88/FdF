# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 18:07:59 by mshehata          #+#    #+#              #
#    Updated: 2023/02/16 02:16:20 by m_kamal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAC = fdf
LINUX = fdf

LIBFT =	./libft/srcs/ft_split.c ./libft/srcs/ft_atoi.c ./libft/srcs/ft_bzero.c ./libft/srcs/ft_calloc.c ./libft/srcs/get_next_line.c\
		./libft/srcs/ft_strjoin.c ./libft/srcs/ft_itoa.c ./libft/srcs/ft_lstclear.c\
		./libft/srcs/ft_strncmp.c ./libft/srcs/ft_lstdelone.c ./libft/srcs/ft_lstiter.c\
		./libft/srcs/ft_strchr.c ./libft/srcs/ft_lstlast.c ./libft/srcs/ft_lstnew.c ./libft/srcs/ft_memmove.c\
		./libft/srcs/ft_strlen.c ./libft/srcs/ft_lstsize.c ./libft/srcs/ft_memchr.c ./libft/srcs/ft_memcmp.c ./libft/srcs/ft_memcpy.c\
		./libft/srcs/ft_substr.c ./libft/srcs/ft_memset.c ./libft/srcs/ft_putchar_fd.c ./libft/srcs/ft_putnbr_fd.c ./libft/srcs/ft_putstr_fd.c\
		./libft/srcs/ft_strdup.c ./libft/srcs/ft_strlcat.c ./libft/srcs/ft_strlcpy.c ./libft/srcs/ft_strnstr.c ./libft/srcs/ft_strtrim.c\

SRCS = ./sources/main.c ./sources/hooks.c ./sources/line.c ./sources/errors.c ./sources/utils.c ./sources/parsing.c\
		./sources/map_size.c ./sources/render.c ./sources/projection.c

OFILES = $(LIBFT:.c=.o) $(SRCS:.c=.o)

CC = gcc -g3

FLAGS = -Wall -Wextra -Werror #-fsanitize=address #remove -g before submission

RM = rm -f

all :	$(LINUX)

$(LINUX):	ANNOUNCE $(OFILES)
	$(CC) $(FLAGS) $(OFILES) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(LINUX)

#$(MAC):	ANNOUNCE $(OFILES)
#	$(CC) $(FLAGS) $(OFILES) -Lmlx_mac -lmlx -framework OpenGL -framework AppKit -o $(MAC)

ANNOUNCE:
	@echo "\033[0;33mCompiling FdF..."

clean:
	@echo "\033[31mRemoving .o files"
	@$(RM) $(OFILES)

fclean: clean
	@echo "\033[31mRemoving FdF"
	@$(RM) $(LINUX)

re: fclean all

.SILENT: $(LINUX) $(OFILES)

.PHONY: all clean fclean re

#ifeq ($(shell uname -s), Linux)
#	MLX_DIR		=	minilibx_linux
#	MLX			=	libmlx_Linux.a
#	LINK_MLX	=	-I$(MLX_DIR) -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz
#endif

#ifeq ($(shell uname -s), Darwin)
#	MLX_DIR		=	minilibx_mac
#	MLX			=	libmlx.a
#	LINK_MLX	=	-L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
#endif
#valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./fdf ./maps/42.fdf


