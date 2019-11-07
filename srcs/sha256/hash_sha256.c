/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_sha256.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:11:05 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/07 21:50:02 by ldedier          ###   ########.fr       */
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

/*
 s0 := (w[i-15] rightrotate  7) xor (w[i-15] rightrotate 18) xor (w[i-15] rightshift  3)
 s1 := (w[i- 2] rightrotate 17) xor (w[i- 2] rightrotate 19) xor (w[i- 2] rightshift 10)
 w[i] := w[i-16] + s0 + w[i-7] + s1
*/
void	extend_sha_message_schedule_array(uint32_t *w)
{
	int			i;
	uint32_t	s0;
	uint32_t	s1;

	i = 16;
	while (i < 64)
	{
		s0 = rr(w[i - 15], 7) ^ rr(w[i - 15], 18) ^ (w[i - 15] >> 3);
//		ft_printf("%.8x\n", w[0]);
		ft_printf("%.8x\n", w[1]);
		ft_printf("%032b\n", w[1]);
	
		ft_printf("%.8x\n", rr(w[i - 15], 7));
		ft_printf("%.8x\n", rr(w[i - 15], 18));
		ft_printf("%.8x\n", w[i - 15] >> 3);

		ft_printf("\t\t%032b\n", w[i - 15]);
		ft_printf("rot 7:\t\t%032b\n", rr(w[i - 15], 7));
		ft_printf("rot 18:\t\t%032b\n", rr(w[i - 15], 18));
		ft_printf("shift 3:\t%032b\n", w[i - 15] >> 3);
	
		ft_printf("s0:\t%.8x\n", s0);
		exit(1);
		s1 = rr(w[i - 2], 17) ^ rr(w[i - 2], 19) ^ (w[i - 2] >> 10);
		w[i] = w[i - 16] + s0 + w[i - 7] + s1;
		i++;
	}
	i = 0;
	while (i < 64)
	{
		ft_printf("%d: %.8x\n", i, w[i]);
		i++;
	}
}

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
		sha->h = r.temp1 + r.temp2;
		i++;
	}
}

void    print_sha(t_sha256 *sha)
{
	ft_printf("word h0 = %.8x\n", sha->h0);
	ft_printf("word h1 = %.8x\n", sha->h1);
	ft_printf("word h2 = %.8x\n", sha->h2);
	ft_printf("word h3 = %.8x\n", sha->h3);
	ft_printf("word h4 = %.8x\n", sha->h4);
	ft_printf("word h5 = %.8x\n", sha->h5);
	ft_printf("word h6 = %.8x\n", sha->h6);
	ft_printf("word h7 = %.8x\n", sha->h7);
}

void    print_sha_int(t_sha256 *sha)
{
	ft_printf("word h0 = %d\n", sha->h0);
	ft_printf("word h1 = %d\n", sha->h1);
	ft_printf("word h2 = %d\n", sha->h2);
	ft_printf("word h3 = %d\n", sha->h3);
	ft_printf("word h4 = %d\n", sha->h4);
	ft_printf("word h5 = %d\n", sha->h5);
	ft_printf("word h6 = %d\n", sha->h6);
	ft_printf("word h7 = %d\n", sha->h7);
}

char    *ft_hash_sha256_message(t_sha256 *sha256,
			unsigned char *input, size_t size)
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
			w[j] = words[i + j];
			j++;
		}
		extend_sha_message_schedule_array(w);
//		print_sha(sha256);
		initialize_sha_variables(sha256);
		sha256_rounds(sha256, w);
		append_sha_hashes(sha256);
		i += 16;
	}
	print_sha(sha256);
	return (NULL);
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
char *ft_hash_sha256(unsigned char *input, size_t size)
{
	t_sha256  sha;

	init_sha256(&sha);
	if (pad_input_512(&input, &size))
		return (NULL);
	//debug_input_int(input, size);
	return (ft_hash_sha256_message(&sha, input, size));
}
