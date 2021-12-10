/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:54:34 by suan              #+#    #+#             */
/*   Updated: 2021/12/10 15:01:54 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_digit(char *s)
{
    if (*s == '-' || *s == '+')
        s++;
    while (*s)
    {
        if (ft_isdigit(*s) == 0) // 숫자가 아닐 경우
            return (FALSE);
        s++;
    }
    return (TRUE);
}

// 리턴값 처리
int ft_exit(t_cmd *cmd)
{
    // 파이프 있으면 무시하는 부분 추가
    // bash-3.2$ exit 1 | cat
    // bash-3.2$ exit 1 a b | cat
    // bash: exit: too many arguments
    if (cmd->size == 1)
        exit(0);
    else if (cmd->size == 2 && check_digit(cmd->node->next->str))
        exit(ft_atoi(cmd->node->str) % 256);
    // bash: exit: ++1: numeric argument required
    else if (cmd->size > 1 && !check_digit(cmd->node->next->str))
    {
        ft_putstr_fd("numeric argument required\n", 2);
        exit(-1);
    }
    else if (cmd->size > 2)
    {
        ft_putstr_fd("exit: too many arguments\n", 2);
        exit(1);
    }
    return (0);
}