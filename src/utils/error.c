/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:43:31 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/15 16:55:30 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	error(char *msg)
{
	printf("%sError: %s %s\n", COLOR_RED, msg, COLOR_NORMAL);
	exit (EXIT_FAILURE);
	return (0);
}

int	error_keep(char *msg)
{
	printf("%sError: %s %s\n", COLOR_RED, msg, COLOR_NORMAL);
	return (0);
}
