/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:02:52 by suan              #+#    #+#             */
/*   Updated: 2021/12/14 00:08:35 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// cd_home
// cd_oldpwd
// get_env -> 빌트인 함수 호출 전에 변경?

/*
cd: cd home
cd ~: cd home
cd ~ 1 1 1: cd home (no error)
cd -: OLDPWD
cd ~-: OLDPWD
bash-3.2$ cd -~

bash: cd: -~: invalid option -> -~, -p, ...
cd: usage: cd [-L|-P] [dir]
*/