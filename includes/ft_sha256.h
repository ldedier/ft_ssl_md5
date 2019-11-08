/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:12:44 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/05 17:12:44 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA256_H
# define FT_SHA256_H

# include "libft.h"


typedef struct		s_sha256
{
	uint32_t		h0;
	uint32_t		h1;
	uint32_t		h2;
	uint32_t		h3;
	uint32_t		h4;
	uint32_t		h5;
	uint32_t		h6;
	uint32_t		h7;
	uint32_t		a;
	uint32_t		b;
	uint32_t		c;
	uint32_t		d;
	uint32_t		e;
	uint32_t		f;
	uint32_t		g;
	uint32_t		h;

}					t_sha256;

typedef struct		s_sha_round
{
	uint32_t		s0;
	uint32_t		s1;
	uint32_t		ch;
	uint32_t		maj;
	uint32_t		temp1;
	uint32_t		temp2;
}					t_sha_round;

char				*ft_hash_sha256(unsigned char *input, size_t size);
char				*ft_hash_sha224(unsigned char *input, size_t size);
void				init_sha256(t_sha256 *sha);
void				init_sha224(t_sha256 *sha);
void				append_sha_hashes(t_sha256 *sha);
void				initialize_sha_variables(t_sha256 *sha);
char				*ft_hash_sha256_message(t_sha256 *sha256,
						unsigned char *input, size_t size, size_t to_print);

#endif
