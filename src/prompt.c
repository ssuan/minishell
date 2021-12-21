/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:37:18 by suan              #+#    #+#             */
/*   Updated: 2021/12/21 18:09:53 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_line(char **line)
{
	*line = readline("\033[34mminishell$ \033[0m");
	if (*line == NULL)
	{
		ft_putstr_fd("\x1b[1A", 1);
		ft_putstr_fd("\x1b[11C", 1);
		ft_putstr_fd("exit\n", 1);
		exit(0);
	}
}

void print_node(t_node *line_node)
{
	t_node *cur_node;
	int loop = 0;

	/* NODE CHECK */
	cur_node = line_node;
	printf("print node ");
	while (cur_node->next != 0)
	{
		printf("%d", loop++);
		cur_node = cur_node->next;
		if (cur_node != 0)
			printf("[%s] ", cur_node->str);
	}
	printf("\n----------------\n");
	// printf("-----PREV CHECK-------\n");
	// // NODE PREV
	// while (cur_node != 0)
	// {
	// 	if (cur_node != 0)
	// 		printf("node[%s]\n", cur_node->str);
	// 	cur_node = cur_node->prev;
	// }
	// printf("________________\n");
}

void print_cmd(t_cmd *tcmd)
{
	t_cmd *cur_tcmd;
	t_node *cur_node;
	int loop;

	cur_tcmd = tcmd;
	while (cur_tcmd != 0)
	{
		cur_node = cur_tcmd->node;
		loop = 0;
		//printf("ad:%p ", cur_node);
		while (cur_node != NULL)
		{
			printf("%d [%s]", cur_node->flag, cur_node->str);
			cur_node = cur_node->next;
		}
		printf("\n");
		cur_tcmd = cur_tcmd->next;
	}
	printf("________________\n");
}

// "\x1b[A": UP, "\x1b[B": DOWN, "\x1b[C": RIGHT, "\x1b[D": LEFT
// \x1b == \033
void	prompt(void)
{
	char	*line;
	t_cmd	*tcmd;

	while (1)
	{
		get_line(&line);
		if (!check_space(line))
		{
			tcmd = parsing(line);
			if (!tcmd)
			{
				free_cmd(tcmd);
				free(line);
				continue ;
			}
			print_cmd(tcmd);
			get_env(tcmd);
			add_history(line);
			execute(tcmd);
			free_cmd(tcmd);
		}
		free(line);
	}
}
