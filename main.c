/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:00:33 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/15 14:29:02 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	t_node	*line_node;
	t_cmd	*tcmd;
	
	t_cmd	*cur_tcmd;
	t_node	*cur_node;
	
	parsing("kndaljfkn klasmnd lkzc lk| cc,>? > \'!!! @ \'#$ ");
	free_cmd(tcmd);
	parsing("kndaljfkn klasmnd lkzc lk| cc,>? > \'!!! @ \'#$ ");
	free_cmd(tcmd);
	parsing("kndaljfkn klasmnd lkzc lk| cc,>? > \'!!! @ \'#$ ");
	free_cmd(tcmd);
	

	system("leaks a.out");
	return (0);
}
