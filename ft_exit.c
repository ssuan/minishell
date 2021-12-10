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

int ft_exit(char **s)
{
    // 구조체에서 사이즈 가져오기
    int     size;
    size = 0;
    while (s[size])
        ++size;
    
    // 파이프 있으면 무시하는 부분 추가
    // bash-3.2$ exit 1 | cat
    // bash-3.2$ exit 1 a b | cat
    // bash: exit: too many arguments
    if (size == 1)
        exit(0);
    else if (size == 2 && check_digit(s[1]))
        exit(ft_atoi(s[1]) % 256);
    // bash: exit: ++1: numeric argument required
    else if (size > 1 && !check_digit(s[1]))
    {
        ft_putstr_fd("numeric argument required\n", 2);
        exit (-1);
    }
    else if (size > 2)
    {
        ft_putstr_fd("exit: too many arguments\n", 2);
        exit(1);
    }
    return (0);
}