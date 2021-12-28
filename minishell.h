/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:42:52 by minjkim2          #+#    #+#             */
/*   Updated: 2021/12/28 15:06:08 by suan             ###   ########.fr       */
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
# include <sys/stat.h>
# include <errno.h>
# include <sys/types.h> 
# include <fcntl.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

# define FAIL 0
# define SUCCESS 1

# define TRUE 1
# define FALSE 0

# define STR_ENV_SETTING_ERR "Minishell is failed to set\
							environmental variables."

# define COLOR_NORMAL "\033[0m"
# define COLOR_RED "\033[31m"
# define COLOR_GREN "\033[32m"
# define COLOR_YELLOW "\033[33m"
# define COLOR_BLUE "\033[34m"
# define COLOR_PRPL "\033[35m"
# define COLOR_AQUA "\033[36m"

# define SPECIFIER "|<>"

# define STRING 0
# define SQUOTE 1
# define DQUOTE 2
# define PIPE 3
# define REDIR_IN 4
# define REDIR_IN_A 5
# define REDIR_OUT 6
# define REDIR_OUT_A 7

typedef struct s_node
{
	char			*str;
	int				flag;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_cmd
{
	int				size;
	struct s_node	*node;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

typedef struct s_state
{
	char	**env;
	int		env_len;
	int		exit_status;
	int		flag;
	int		cmd_cnt;
	int		backup_cnt;
	int		pipe_set[2][2];
	int		fork;
	int		redir_in;
	int		redir_out;
}	t_state;

t_state	g_state;

/* NODE */
t_node	*ft_nodenew(void *content, int flag);
void	ft_nodeadd_front(t_node **node, t_node *new);
int		ft_nodesize(t_node *node);
t_node	*ft_nodelast(t_node *node);
void	ft_nodeadd_back(t_node **node, t_node *new);
void	ft_nodedelone(t_node *node, void (*del)(void *));
void	ft_nodeclear(t_node **node, void (*del)(void *));
void	ft_nodeiter(t_node *node, void (*f)(void *));
t_node	*ft_nodemap(t_node *node, void *(*f)(void *),
			void (*del)(void *));

/* cmd */
t_cmd	*ft_cmdnew(void *content);
void	ft_cmdadd_front(t_cmd **cmd, t_cmd *new);
int		ft_cmdsize(t_cmd *cmd);
t_cmd	*ft_cmdlast(t_cmd *cmd);
void	ft_cmdadd_back(t_cmd **cmd, t_cmd *new);
void	ft_cmddelone(t_cmd *cmd, void (*del)(void *));
void	ft_cmdclear(t_cmd **cmd, void (*del)(void *));
void	ft_cmditer(t_cmd *cmd, void (*f)(void *));
t_cmd	*ft_cmdmap(t_cmd *cmd, void *(*f)(void *),
			void (*del)(void *));

void	set_signal(void);
void	prompt(void);

/* utils */
int		free_arr2(char **s);
char	*find_path(char *cmd);
int		check_space(char *s);
char	**set_cmds(t_cmd *cmd);

/* builtin */
void	ft_exit(t_cmd *cmd);
int		ft_pwd(void);
int		ft_echo(t_cmd *cmd);
int		ft_env(t_cmd *cmd);
int		ft_export(t_cmd *cmd);
int		ft_unset(t_cmd *cmd);
int		ft_cd(t_cmd *cmd);

/* env */
void	print_export(void);
int		init_env(int argc, char **argv, char **envp);
void	get_env(t_cmd *cmd);
char	*find_value(char *key);
char	*get_key(char *str);
char	*get_value(char *str);
void	env_update(char *key, char *value);

/* execute */
int		pre_execute(t_cmd *cmd);
void	execute(t_cmd *cmd);
int		is_builtin(t_cmd *cmd);
void	builtin_div(t_cmd *tcmd);
void	builtin(t_cmd *cmd);
void	non_builtin(t_cmd *cmd);

/* redirect */
int		connect_redirect(t_cmd *cmd);
int		redirect_in(char *file);
int		redirect_out(char *file);
int		redirect_out_append(char *file);
void	here_doc(t_cmd *cmd);
void	connect_pipe(int fd[2], int io);
void	set_pipe(void);

/* parsing */
t_node	*parse_line(char *line);
int		parse_space(char **line, char **save_str, t_node *line_node);
int		parse_quote(char **line, char **save_str, t_node *line_node);
int		parse_pipe(char **line, char **save_str, t_node *line_node);
int		parse_redir(char **line, char **save_str, t_node *line_node);
int		save_str_node(t_node *node, char **save_str);
int		save_str_join(char **line, char **save_str);
int		free_node(t_node *node);
int		free_cmd(t_cmd *tcmd);
t_cmd	*parsing(char *line);
int		cmd_connect_break(t_cmd *tcmd);
t_cmd	*node_to_cmd(t_node *node);

/* error */
void	error(char *msg, int status);
void	print_error(char *command, char *msg);
void	print_error_exit(char *command, char *msg, int exit_status);
void	print_error2(char *command, char *input, char *msg);
void	print_error3(char *command, char *input, char *msg);

#endif
