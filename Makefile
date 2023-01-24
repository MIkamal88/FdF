# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 18:07:59 by mshehata          #+#    #+#              #
#    Updated: 2023/01/24 15:57:46 by mshehata         ###   ########.fr        #
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

SRCS = ./sources/main.c

OFILES = $(LIBFT:.c=.o) $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -g #remove -g before submission

RM = rm -f

all :	$(MAC)

#$(LINUX):	ANNOUNCE $(OFILES)
#	$(CC) $(OFILES) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(LINUX)

$(MAC):	ANNOUNCE $(OFILES)
	$(CC) $(OFILES) -Lmlx_mac -lmlx -framework OpenGL -framework AppKit -o $(MAC)

ANNOUNCE:
	@echo "\033[0;33mCompiling FdF..."

clean:
	@echo "\033[31mRemoving .o files"
	@$(RM) $(OFILES)

fclean: clean
	@echo "\033[31mRemoving FdF"
	@$(RM) $(MAC)

re: fclean all

.SILENT: $(MAC) $(OFILES)

.PHONY: all clean fclean re
