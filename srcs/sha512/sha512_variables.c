/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 02:31:52 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/27 14:29:23 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	initialize_sha512_variables(t_sha512 *sha)
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

void	append_sha512_hashes(t_sha512 *sha)
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

void	init_sha512(t_sha512 *sha)
{
	sha->h0 = 0x6a09e667f3bcc908;
	sha->h1 = 0xbb67ae8584caa73b;
	sha->h2 = 0x3c6ef372fe94f82b;
	sha->h3 = 0xa54ff53a5f1d36f1;
	sha->h4 = 0x510e527fade682d1;
	sha->h5 = 0x9b05688c2b3e6c1f;
	sha->h6 = 0x1f83d9abfb41bd6b;
	sha->h7 = 0x5be0cd19137e2179;
}
