/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:43:31 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/07 15:17:13 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     error(char *msg)
{
        printf("%sError: %s %s\n", COLOR_RED, msg, COLOR_NORMAL);
        exit (EXIT_FAILURE);
}
