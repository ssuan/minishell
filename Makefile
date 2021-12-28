# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/21 14:05:19 by suan              #+#    #+#              #
#    Updated: 2021/12/28 11:51:56 by sunbchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

LIBFT = libft
LIBFT_LIB = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

READLINE_LIB  = -lreadline -L/usr/local/opt/readline/lib
READLINE_INC = -I/usr/local/opt/readline/include

SRC_DIR = src/

SRC_NAME = builtin/ft_cd.c builtin/ft_echo.c builtin/ft_env.c\
		builtin/ft_exit.c builtin/ft_export.c builtin/ft_pwd.c\
		builtin/ft_unset.c env/env.c env/get_env.c env/init_env.c\
		env/print_export.c execute/builtin.c execute/execute.c\
		execute/non_builtin.c execute/redirect.c parse/cmd_func.c\
		parse/free_func.c parse/parse_pipe.c parse/parse_quote.c\
		parse/parse_redir.c parse/parse_space.c parse/parse.c\
		parse/save_str.c utils/error.c utils/execute_utils.c\
		utils/utils.c prompt.c signal.c\
		ft_cmd/ft_cmdadd_back.c ft_cmd/ft_cmdadd_front.c ft_cmd/ft_cmdclear.c\
		ft_cmd/ft_cmddelone.c ft_cmd/ft_cmditer.c ft_cmd/ft_cmdlast.c\
		ft_cmd/ft_cmdmap.c ft_cmd/ft_cmdnew.c ft_cmd/ft_cmdsize.c\
		ft_node/ft_nodeadd_back.c ft_node/ft_nodeadd_front.c ft_node/ft_nodeclear.c\
		ft_node/ft_nodedelone.c ft_node/ft_nodeiter.c ft_node/ft_nodelast.c\
		ft_node/ft_nodemap.c ft_node/ft_nodenew.c ft_node/ft_nodesize.c\

SRCS = $(addprefix $(SRC_DIR), $(SRC_NAME)) main.c

OBJS = $(SRCS:.c=.o)
INC = -I./

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC) $(READLINE_INC) 

$(NAME): $(OBJS)
	make all -C $(LIBFT)/
	$(CC) $(CFLAGS) $(OBJS) $(INC) $(READLINE_INC) $(READLINE_LIB) $(LIBFT)/$(LIBFT_LIB) -o $(NAME) 

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re: clean all

bonus: all

.PHONY: all clean fclean re bonus
