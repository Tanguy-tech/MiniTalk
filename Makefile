# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/24 15:49:39 by Tanguy            #+#    #+#              #
#    Updated: 2021/08/10 08:24:46 by tanguy           ###   ########.fr        #
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

CLIENT = client

SERVER = server

HEADER = minitalk.h

LIBFT = libft/libft.a

CC = gcc

RM = rm -rf

FLAGS = -Wall -Werror -Wextra

all	:	comp_lib $(SERVER) $(CLIENT)		
			
comp_lib :
			@make -C libft

$(SERVER) :	part_server.o
			@$(CC) $(FLAGS) part_server.o -I $(HEADER) $(LIBFT) -o $(SERVER)
			@printf "$(GREEN)Server built with success!$(END)\n"

$(CLIENT) : part_client.o
			@$(CC) $(FLAGS) part_client.o -I $(HEADER) $(LIBFT) -o $(CLIENT)
			@printf "$(GREEN)Client built with success!$(END)\n"

%.o: %.c $(HEADER) $(LIBFT)
		@$(CC) $(FLAGS) -c $< -o $@ -I $(HEADER)

norme:		
			@norminette libft/*.c
			@norminette part_client.c
			@norminette part_server.c

clean :
			@make clean -C libft 
			@$(RM) libft/libft.a
			@$(RM) part_client.o part_server.o
			@$(RM) server client
			@printf "$(ERASE)$(RED)-> All files .o cleaned$(END)\n"

fclean : clean
			@$(RM) $(CLIENT) $(SERVER)
			@printf "$(ERASE)$(RED)-> All files cleaned$(END)\n"

re:			fclean all

.PHONY: 	all fclean clean re