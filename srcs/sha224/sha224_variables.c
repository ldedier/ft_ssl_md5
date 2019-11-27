/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:27:57 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/27 14:28:06 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	init_sha224(t_sha256 *sha)
{
	sha->h0 = 0xc1059ed8;
	sha->h1 = 0x367cd507;
	sha->h2 = 0x3070dd17;
	sha->h3 = 0xf70e5939;
	sha->h4 = 0xffc00b31;
	sha->h5 = 0x68581511;
	sha->h6 = 0x64f98fa7;
	sha->h7 = 0xbefa4fa4;
}