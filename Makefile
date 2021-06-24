# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Tanguy <Tanguy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/24 15:49:39 by Tanguy            #+#    #+#              #
#    Updated: 2021/06/24 16:23:08 by Tanguy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ERASE       =   \033[2K\r
GREY        =   \033[30m
RED         =   \033[31m
GREEN       =   \033[32m
YELLOW      =   \033[33m
BLUE        =   \033[34m
PINK        =   \033[35m
CYAN        =   \033[36m
WHITE       =   \033[37m
BOLD        =   \033[1m
UNDER       =   \033[4m
SUR         =   \033[7m
END         =   \033[0m

CC = gcc

FLAGS = -Wall -Werror -Wextra

RM = rm -rf

SRCS = client_part.c server_part.c

UTILS = 

INCS = minitalk.h

OBJS_SRCS = $(addprefix ./srcs/, $(SRCS:.c=.o))

OBJS_UTILS = $(addprefix ./utils/, $(UTILS:.c=.o))

OBJS_INCS = $(addprefix ./includes/, $(INCS))

$(NAME):	$(OBJS_SRCS) $(OBJS_UTILS)
				@$(CC) $(CFLAGS) $(OBJS_SRCS) $(OBJS_UTILS) -I $(OBJS_INCS) -o minitalk
				@printf "$(CYAN)-> Executable file minitalk created with success!\n$(BLUE)"

all:		$(NAME)

%.o: %.c $(OBJS_INCS)
		 @$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I ./includes
		 @printf "$(ERASE)$(YELLOW)$<....$(END)"

norme:		
			norminette $(addprefix ./srcs/, $(SRCS))

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(OBJS_SRCS)
			@$(RM) $(OBJS_UTILS)
			@printf "$(ERASE)$(RED)-> All files .o cleaned$(END)\n"
			@printf "$(ERASE)$(RED)-> All minilibx files cleaned$(END)\n"

re:			fclean all

.PHONY: 	all fclean clean re