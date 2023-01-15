# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 18:07:59 by mshehata          #+#    #+#              #
#    Updated: 2023/01/15 10:19:59 by mshehata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT =	./Libft/srcs/ft_split.c ./Libft/srcs/ft_atoi.c ./Libft/srcs/ft_bzero.c ./Libft/srcs/ft_calloc.c ./Libft/srcs/get_next_line.c\
		./Libft/srcs/ft_strjoin.c ./Libft/srcs/ft_itoa.c ./Libft/srcs/ft_lstadd_back.c ./Libft/srcs/ft_lstclear.c\
		./Libft/srcs/ft_strncmp.c ./Libft/srcs/ft_lstadd_front.c ./Libft/srcs/ft_lstdelone.c ./Libft/srcs/ft_lstiter.c\
		./Libft/srcs/ft_strchr.c ./Libft/srcs/ft_lstlast.c ./Libft/srcs/ft_lstmap.c ./Libft/srcs/ft_lstnew.c ./Libft/srcs/ft_memmove.c\
		./Libft/srcs/ft_strlen.c ./Libft/srcs/ft_lstsize.c ./Libft/srcs/ft_memchr.c ./Libft/srcs/ft_memcmp.c ./Libft/srcs/ft_memcpy.c\
		./Libft/srcs/ft_substr.c ./Libft/srcs/ft_memset.c ./Libft/srcs/ft_putchar_fd.c ./Libft/srcs/ft_putnbr_fd.c ./Libft/srcs/ft_putstr_fd.c\
		./Libft/srcs/ft_strdup.c ./Libft/srcs/ft_strlcat.c ./Libft/srcs/ft_strlcpy.c ./Libft/srcs/ft_strnstr.c ./Libft/srcs/ft_strtrim.c\

SRCS = ./sources/main.c

OFILES = $(LIBFT:.c=.o) $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -g #remove -g before submission

RM = rm -f

all :	$(NAME)

$(NAME):	ANNOUNCE $(OFILES)
	$(CC) $(OFILES) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

ANNOUNCE:
	@echo "\033[0;33mCompiling FdF..."

clean:
	@echo "\033[31mRemoving .o files"
	@$(RM) $(OFILES)

fclean: clean
	@echo "\033[31mRemoving FdF"
	@$(RM) $(NAME)

re: fclean all

.SILENT: $(NAME) $(OFILES)

.PHONY: all clean fclean re
