/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:42:52 by minjkim2          #+#    #+#             */
/*   Updated: 2021/12/14 18:42:58 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"

#define FAIL 0
#define SUCCESS 1

#define TRUE 1
#define FALSE 0

#define STR_ENV_SETTING_ERR "Minishell is failed to set environmental variables."
#define STR_SINGLE_QUOTE_ERR "This Syntex has only one quote charictor"
#define SPACE_CORDSET "\t\v"

#define COLOR_NORMAL "\033[0m"
#define COLOR_RED "\033[31m"
#define COLOR_GREN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_BLUE "\033[34m"
#define COLOR_PRPL "\033[35m"
#define COLOR_AQUA "\033[36m"

#define SPECIFIER "|<>"

typedef struct s_node
{
	char *str;
	struct s_node *next;
	struct s_node *prev;
} t_node;

typedef struct s_cmd
{
	int size;
	struct s_node *node;
	struct s_cmd *next;
	struct s_cmd *prev;
} t_cmd;

typedef struct s_state
{
	char **env;
	int env_len;
	int exit_status;
} t_state;

t_state g_state;

int error(char *msg);
int initialize_data(int argc, char **argv, char **envp);
t_node *parse_line(char *line);
t_cmd *node_to_cmd(t_node *node);

void print_node(t_node *line_node);
void print_cmd(t_cmd *tcmd);

/* NODE */
t_node *ft_nodenew(void *content);
void ft_nodeadd_front(t_node **node, t_node *new);
int ft_nodesize(t_node *node);
t_node *ft_nodelast(t_node *node);
void ft_nodeadd_back(t_node **node, t_node *new);
void ft_nodedelone(t_node *node, void (*del)(void *));
void ft_nodeclear(t_node **node, void (*del)(void *));
void ft_nodeiter(t_node *node, void (*f)(void *));
t_node *ft_nodemap(t_node *node, void *(*f)(void *),
				   void (*del)(void *));

/* cmd */
t_cmd *ft_cmdnew(void *content);
void ft_cmdadd_front(t_cmd **cmd, t_cmd *new);
int ft_cmdsize(t_cmd *cmd);
t_cmd *ft_cmdlast(t_cmd *cmd);
void ft_cmdadd_back(t_cmd **cmd, t_cmd *new);
void ft_cmddelone(t_cmd *cmd, void (*del)(void *));
void ft_cmdclear(t_cmd **cmd, void (*del)(void *));
void ft_cmditer(t_cmd *cmd, void (*f)(void *));
t_cmd *ft_cmdmap(t_cmd *cmd, void *(*f)(void *),
				 void (*del)(void *));

void set_signal(void);
int check_space(char *s);
void execution(t_cmd *cmd);

char **set_cmds(t_cmd *cmd);

void	ft_exit(t_cmd *cmd);
int	ft_pwd(void);
int	ft_echo(t_cmd *cmd);
int	ft_env(t_cmd *cmd);
int	ft_export(t_cmd *cmd);
int	ft_unset(t_cmd *cmd);
int	ft_cd(t_cmd *cmd);

void	print_export(void);

char	*find_value(char *key);
void	prompt(void);
int cmd_connect_break(t_cmd *tcmd);

int	free_split(char **s);
char	*find_path(char *cmd);

char	*get_key(char *str);
char	*get_value(char *str);
void	env_update(char *key, char *value);

void    dollor_to_env(t_cmd *cmd);

#endif
