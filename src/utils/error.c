/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:43:31 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/12 20:30:45 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int     error(char *msg)
{
    printf("%sError: %s %s\n", COLOR_RED, msg, COLOR_NORMAL);
    exit (EXIT_FAILURE);
	return (0);
}

int     error_keep(char *msg)
{
    printf("%sError: %s %s\n", COLOR_RED, msg, COLOR_NORMAL);
	return (0);
}

