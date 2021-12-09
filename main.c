/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:00:33 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/09 14:22:46 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
    int loop;

    loop = 0;

    initialize_data(argc, argv, envp);
    parse_cmd("\"ABCDEF\"FFFF");
    
    // while (g_state.env[loop] != 0)
    // {
    //     printf("[%d] = [%s]\n", loop, g_state.env[loop]);
    //     loop++;
    // }
    // error("TEST");
}
