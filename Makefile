# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 18:07:59 by mshehata          #+#    #+#              #
#    Updated: 2023/01/14 18:14:34 by mshehata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT =

SRCS =

OFILES =

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
