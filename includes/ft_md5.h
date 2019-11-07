/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:48:36 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/04 14:48:36 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
# define FT_MD5_H

# include "libft.h"

# define MD5_NB_ROUNDS	4

typedef struct		s_md_buffers
{
	uint32_t		a;
	uint32_t		b;
	uint32_t		c;
	uint32_t		d;
	uint32_t		aa;
	uint32_t		bb;
	uint32_t		cc;
	uint32_t		dd;
}					t_md_buffers;

typedef struct		s_md5
{
	t_md_buffers	buffs;
}					t_md5;

uint64_t			g_st[64];

char				*ft_hash_md5(unsigned char *input, size_t size);
void				md5_rounds(t_md_buffers *buffer, uint32_t *x_buffer);

char				*generate_hash_from_buffers(t_md_buffers *buffers);
void				append_buffs(t_md_buffers *buffers);
void				save_buffs(t_md_buffers *buffers);
void				init_md_buffers(t_md_buffers *buffers);
void				print_buffers(t_md_buffers *buffers);
void				print_buffers_int(t_md_buffers *buffers);


uint32_t			md_f(uint32_t x, uint32_t y, uint32_t z);
uint32_t			md_g(uint32_t x, uint32_t y, uint32_t z);
uint32_t			md_h(uint32_t x, uint32_t y, uint32_t z);
uint32_t			md_i(uint32_t x, uint32_t y, uint32_t z);

char				*generate_hash_from_buffers(t_md_buffers *buffers);
#endif
