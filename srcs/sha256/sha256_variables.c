/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 02:31:52 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/08 02:31:52 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	initialize_sha_variables(t_sha256 *sha)
{
	sha->a = sha->h0;
	sha->b = sha->h1;
	sha->c = sha->h2;
	sha->d = sha->h3;
	sha->e = sha->h4;
	sha->f = sha->h5;
	sha->g = sha->h6;
	sha->h = sha->h7;
}

void	append_sha_hashes(t_sha256 *sha)
{
	sha->h0 += sha->a;
	sha->h1 += sha->b;
	sha->h2 += sha->c;
	sha->h3 += sha->d;
	sha->h4 += sha->e;
	sha->h5 += sha->f;
	sha->h6 += sha->g;
	sha->h7 += sha->h;
}

void		init_sha224(t_sha256 *sha)
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

void		init_sha256(t_sha256 *sha)
{
	sha->h0 = 0x6a09e667;
	sha->h1 = 0xbb67ae85;
	sha->h2 = 0x3c6ef372;
	sha->h3 = 0xa54ff53a;
	sha->h4 = 0x510e527f;
	sha->h5 = 0x9b05688c;
	sha->h6 = 0x1f83d9ab;
	sha->h7 = 0x5be0cd19;
}
