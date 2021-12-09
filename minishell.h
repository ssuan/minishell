/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:42:52 by minjkim2          #+#    #+#             */
/*   Updated: 2021/12/09 18:30:57 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./libft/libft.h"

# define FAIL 0
# define SUCCESS 1

# define STR_ENV_SETTING_ERR "Minishell is failed to set environmental variables."
# define STR_SINGLE_QUOTE_ERR "This Syntex has only one quote charictor"
# define SPACE_CORDSET "\t\v"

# define COLOR_NORMAL	"\033[0m"
# define COLOR_RED		"\033[31m"
# define COLOR_GREN		"\033[32m"
# define COLOR_YELLOW	"\033[33m"
# define COLOR_BLUE		"\033[34m"
# define COLOR_PRPL		"\033[35m"
# define COLOR_AQUA		"\033[36m"

typedef struct s_node
{
	char			*str;
	struct s_node	*next;
	struct s_node	*prev;
}t_node;


typedef struct s_cmd
{
	char			**cmd;
	int				size;
	struct s_node	*first;
	struct s_node	*last;
}t_cmd;

typedef struct s_state
{
	char			**env;
	int				env_len;
}t_state;

t_state				g_state;

int     error(char *msg);
int		initialize_data(int argc, char **argv, char **envp);
t_node	*parse_cmd(char *line);

/* NODE */
t_node				*ft_nodenew(void *content);
void				ft_nodeadd_front(t_node **node, t_node *new);
int					ft_nodesize(t_node *node);
t_node				*ft_nodelast(t_node *node);
void				ft_nodeadd_back(t_node **node, t_node *new);
void				ft_nodedelone(t_node *node, void (*del)(void *));
void				ft_nodeclear(t_node **node, void (*del)(void *));
void				ft_nodeiter(t_node *node, void (*f)(void *));
t_node				*ft_nodemap(t_node *node, void *(*f)(void *),
						void (*del)(void *));

#endif
