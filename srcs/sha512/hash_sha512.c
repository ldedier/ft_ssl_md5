/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_sha512.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 21:00:40 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/10 21:00:40 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint64_t g_cr_512[80] =
{
	0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f,
	0xe9b5dba58189dbbc, 0x3956c25bf348b538, 0x59f111f1b605d019,
	0x923f82a4af194f9b, 0xab1c5ed5da6d8118, 0xd807aa98a3030242,
	0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
	0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235,
	0xc19bf174cf692694, 0xe49b69c19ef14ad2, 0xefbe4786384f25e3,
	0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65, 0x2de92c6f592b0275,
	0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
	0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f,
	0xbf597fc7beef0ee4, 0xc6e00bf33da88fc2, 0xd5a79147930aa725, 
	0x06ca6351e003826f, 0x142929670a0e6e70, 0x27b70a8546d22ffc,
	0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
	0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6,
	0x92722c851482353b, 0xa2bfe8a14cf10364, 0xa81a664bbc423001,
	0xc24b8b70d0f89791, 0xc76c51a30654be30, 0xd192e819d6ef5218, 
	0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
	0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99,
	0x34b0bcb5e19b48a8, 0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb,
	0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3, 0x748f82ee5defb2fc,
	0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec, 
	0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915,
	0xc67178f2e372532b, 0xca273eceea26619c, 0xd186b8c721c0c207,
	0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178, 0x06f067aa72176fba,
	0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b,
	0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc, 
	0x431d67c49c100d4c, 0x4cc5d4becb3e42b6, 0x597f299cfc657e2a,
	0x5fcb6fab3ad6faec, 0x6c44198c4a475817
};

/*
	s0 := (w[i-15] rightrotate 1) xor (w[i-15] rightrotate 8) xor (w[i-15] rightshift 7)
	s1 := (w[i-2] rightrotate 19) xor (w[i-2] rightrotate 61) xor (w[i-2] rightshift 6)
*/

void	extend_sha_message_schedule_array512(uint64_t *w)
{
	int			i;
	uint64_t	s0;
	uint64_t	s1;

	i = 16;
	while (i < 80)
	{
		s0 = rr64(w[i - 15], 1) ^ rr64(w[i - 15], 8) ^ (w[i - 15] >> 7);
		s1 = rr64(w[i - 2], 19) ^ rr64(w[i - 2], 61) ^ (w[i - 2] >> 6);
		w[i] = w[i - 16] + s0 + w[i - 7] + s1;
		i++;
	}
}

void	sha512_rounds(t_sha512 *sha, uint64_t *w)
{
	t_sha512_round	r;
	int				i;

	i = 0;
	while (i < 80)
	{
		r.s1 = rr64(sha->e, 14) ^ rr64(sha->e, 18) ^ rr64(sha->e, 41);
		r.ch = (sha->e & sha->f) ^ (~sha->e & sha->g);
		r.temp1 = sha->h + r.s1 + r.ch + g_cr_512[i] + w[i];
		r.s0 = rr64(sha->a, 28) ^ rr64(sha->a, 34) ^ rr64(sha->a, 39);
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

char	*ft_sha512_generate_digest(t_sha512 *sha, size_t size)
{
	char *res;

	if (!(res = ft_strnew(128)))
		return (NULL);
	ft_sprintf(res, "%016lx", sha->h0);
	ft_sprintf(res + 16, "%016llx", sha->h1);
	ft_sprintf(res + 32, "%016llx", sha->h2);
	ft_sprintf(res + 48, "%016llx", sha->h3);
	ft_sprintf(res + 64, "%016llx", sha->h4);
	ft_sprintf(res + 80, "%016llx", sha->h5);
	if (size >= 7)
		ft_sprintf(res + 96, "%016llx", sha->h6);
	if (size >= 8)
		ft_sprintf(res + 112, "%016llx", sha->h7);
	return (res);

}

char    *ft_hash_sha512_message(t_sha512 *sha512,
		unsigned char *input, size_t size, size_t to_print)
{
	size_t		i;
	size_t		j;
	size_t		nb_words;
	uint64_t	*words;
	uint64_t	w[80];

	nb_words = size / sizeof(uint64_t);
	words = (uint64_t *)input;
	i = 0;
	while (i < nb_words)
	{
		j = 0;
		while (j < 16)
		{
			w[j] = (uint64_t)words[i + j];
			swap_bytes(&w[j], sizeof(uint64_t), 1);
			j++;
		}
		extend_sha_message_schedule_array512(w);
		initialize_sha512_variables(sha512);
		sha512_rounds(sha512, w);
		append_sha512_hashes(sha512);
		i += 16;
	}
	return (ft_sha512_generate_digest(sha512, to_print));
}

char *ft_hash_sha512(unsigned char **input, size_t size)
{
	t_sha512  sha;

	init_sha512(&sha);
	if (pad_input_1024(input, &size, 1))
		return (NULL);
	return (ft_hash_sha512_message(&sha, *input, size, 8));
}
