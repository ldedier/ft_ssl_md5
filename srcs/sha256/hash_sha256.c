/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_sha256.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:11:05 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/27 13:46:05 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t g_cr[64] =
{
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
	0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786,
	0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
	0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
	0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a,
	0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

void	extend_sha_message_schedule_array(uint32_t *w)
{
	int			i;
	uint32_t	s0;
	uint32_t	s1;

	i = 16;
	while (i < 64)
	{
		s0 = rr(w[i - 15], 7) ^ rr(w[i - 15], 18) ^ (w[i - 15] >> 3);
		s1 = rr(w[i - 2], 17) ^ rr(w[i - 2], 19) ^ (w[i - 2] >> 10);
		w[i] = w[i - 16] + s0 + w[i - 7] + s1;
		i++;
	}
}

void	sha256_rounds(t_sha256 *sha, uint32_t *w)
{
	t_sha_round	r;
	int			i;

	i = 0;
	while (i < 64)
	{
		r.s1 = rr(sha->e, 6) ^ rr(sha->e, 11) ^ rr(sha->e, 25);
		r.ch = (sha->e & sha->f) ^ (~sha->e & sha->g);
		r.temp1 = sha->h + r.s1 + r.ch + g_cr[i] + w[i];
		r.s0 = rr(sha->a, 2) ^ rr(sha->a, 13) ^ rr(sha->a, 22);
		r.maj = (sha->a & sha->b) ^ (sha->a & sha->c) ^ (sha->b & sha->c);
		r.temp2 = r.s0 + r.maj;
		sha->h = sha->g;
		sha->g = sha->f;
		sha->f = sha->e;
		sha->e = sha->d + r.temp1;
		sha->d = sha->c;
		sha->c = sha->b;
		sha->b = sha->a;
		sha->a = r.temp1 + r.temp2;
		i++;
	}
}

char	*ft_sha_generate_digest(t_sha256 *sha, size_t size)
{
	char *res;

	if (!(res = ft_strnew(64)))
		return (NULL);
	ft_sprintf(res, "%08x", sha->h0);
	ft_sprintf(res + 8, "%08x", sha->h1);
	ft_sprintf(res + 16, "%08x", sha->h2);
	ft_sprintf(res + 24, "%08x", sha->h3);
	ft_sprintf(res + 32, "%08x", sha->h4);
	ft_sprintf(res + 40, "%08x", sha->h5);
	ft_sprintf(res + 48, "%08x", sha->h6);
	if (size >= 8)
		ft_sprintf(res + 56, "%08x", sha->h7);
	return (res);
}

char	*ft_hash_sha256_message(t_sha256 *sha256,
			unsigned char *input, size_t size, size_t to_print)
{
	size_t		i;
	size_t		j;
	size_t		nb_words;
	uint32_t	*words;
	uint32_t	w[64];

	nb_words = size / sizeof(uint32_t);
	words = (uint32_t *)input;
	i = 0;
	while (i < nb_words)
	{
		j = 0;
		while (j < 16)
		{
			w[j] = (uint32_t)words[i + j];
			swap_uint32(&w[j]);
			j++;
		}
		extend_sha_message_schedule_array(w);
		initialize_sha_variables(sha256);
		sha256_rounds(sha256, w);
		append_sha_hashes(sha256);
		i += 16;
	}
	return (ft_sha_generate_digest(sha256, to_print));
}

char	*ft_hash_sha256(unsigned char **input, size_t size)
{
	t_sha256	sha;

	init_sha256(&sha);
	if (pad_input_512(input, &size, 1))
		return (NULL);
	return (ft_hash_sha256_message(&sha, *input, size, 8));
}
