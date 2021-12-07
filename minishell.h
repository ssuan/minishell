/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:42:52 by minjkim2          #+#    #+#             */
/*   Updated: 2021/12/07 17:20:33 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
#include "libft/libft.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

# define FAIL 0
# define SUCCESS 1

# define TRUE 1
# define FALSE 0

# define STR_ENV_SETTING_ERR "Minishell is failed to set environmental variables."

# define COLOR_NORMAL	"\033[0m"
# define COLOR_RED		"\033[31m"
# define COLOR_GREN		"\033[32m"
# define COLOR_YELLOW	"\033[33m"
# define COLOR_BLUE		"\033[34m"
# define COLOR_PRPL		"\033[35m"
# define COLOR_AQUA		"\033[36m"

// typedef struct s_node
// {
// 	int				type;
// 	char			*contents;
// 	struct s_node	*next;
// 	struct s_node	*prev;
// }t_node;

// typedef struct s_cmd
// {
// 	int				size;
// 	struct s_node	*first;
// 	struct s_node	*last;
// }t_cmd;

typedef struct s_state
{
	char			**env;
	int				env_len;
}	t_state;

t_state				g_state;

int     error(char *msg);
int		initialize_data(int argc, char **argv, char **envp);

void	set_signal(void);
int	check_space(char *s);

#endif
