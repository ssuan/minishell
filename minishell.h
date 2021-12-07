/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:42:52 by minjkim2          #+#    #+#             */
/*   Updated: 2021/12/07 14:46:37 by sunbchoi         ###   ########.fr       */
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
}t_state;

t_state				g_state;

int     error(char *msg);
int		initialize_data(int argc, char **argv, char **envp);

#endif
