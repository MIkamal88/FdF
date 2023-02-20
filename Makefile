# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 18:07:59 by mshehata          #+#    #+#              #
#    Updated: 2023/02/20 21:58:57 by m_kamal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAC = fdf
LINUX = fdf

LIBFT =	./libft/srcs/ft_split.c ./libft/srcs/ft_atoi.c ./libft/srcs/ft_bzero.c ./libft/srcs/ft_calloc.c\
		./libft/srcs/ft_strjoin.c ./libft/srcs/ft_strncmp.c ./libft/srcs/ft_strchr.c\
		./libft/srcs/get_next_line.c ./libft/srcs/ft_strlen.c ./libft/srcs/ft_substr.c\
		./libft/srcs/ft_strdup.c ./libft/srcs/ft_strnstr.c ./libft/srcs/ft_strtrim.c ./libft/srcs/ft_strlcpy.c\

SRCS = ./sources/main.c ./sources/hooks.c ./sources/line.c ./sources/errors.c ./sources/utils.c ./sources/parsing.c\
		./sources/map_size.c ./sources/render.c ./sources/projection.c ./sources/cam.c ./sources/menu.c\

OFILES = $(LIBFT:.c=.o) $(SRCS:.c=.o)

CC = gcc -O3

CFLAGS = -Wall -Wextra -Werror#-fsanitize=address #remove -g before submission

RM = rm -f

all :	$(LINUX)

$(LINUX):	ANNOUNCE $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(LINUX)

#$(MAC):	ANNOUNCE $(OFILES)
#	$(CC) $(CFLAGS) $(OFILES) -Lmlx_mac -lmlx -framework OpenGL -framework AppKit -o $(MAC)

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

#valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./fdf ./maps/42.fdf

