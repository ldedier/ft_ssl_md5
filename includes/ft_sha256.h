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

char *ft_hash_sha256(unsigned char *input, size_t size);

#endif
