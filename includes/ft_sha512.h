/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha512.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 21:11:48 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/10 21:11:48 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA512_H
# define FT_SHA512_H

# include "libft.h"

typedef struct		s_sha512
{
	uint64_t		h0;
	uint64_t		h1;
	uint64_t		h2;
	uint64_t		h3;
	uint64_t		h4;
	uint64_t		h5;
	uint64_t		h6;
	uint64_t		h7;
	uint64_t		a;
	uint64_t		b;
	uint64_t		c;
	uint64_t		d;
	uint64_t		e;
	uint64_t		f;
	uint64_t		g;
	uint64_t		h;
}					t_sha512;

typedef struct		s_sha512_round
{
	uint64_t		s0;
	uint64_t		s1;
	uint64_t		ch;
	uint64_t		maj;
	uint64_t		temp1;
	uint64_t		temp2;
}					t_sha512_round;

char				*ft_hash_sha512(unsigned char *input, size_t size);
char				*ft_hash_sha384(unsigned char *input, size_t size);
void				init_sha512(t_sha512 *sha);
void				init_sha384(t_sha512 *sha);
void				append_sha512_hashes(t_sha512 *sha);
void				initialize_sha512_variables(t_sha512 *sha);
char				*ft_hash_sha512_message(t_sha512 *sha512,
						unsigned char *input, size_t size, size_t to_print);

#endif
