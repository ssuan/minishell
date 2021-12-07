/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:43:31 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/07 14:51:14 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     error(char *msg)
{
        printf("\e[31m\e[1mError\n%s \e[0m \n", msg);
        exit (EXIT_FAILURE);
}
