/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:49:53 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/06 15:49:53 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	md5_round_1(t_md_buffers *b, uint32_t *buff)
{
	b->a = b->b + rl((b->a + md_f(b->b, b->c, b->d) + buff[0] + g_st[0]), 7);
	b->d = b->a + rl((b->d + md_f(b->a, b->b, b->c) + buff[1] + g_st[1]), 12);
	b->c = b->d + rl((b->c + md_f(b->d, b->a, b->b) + buff[2] + g_st[2]), 17);
	b->b = b->c + rl((b->b + md_f(b->c, b->d, b->a) + buff[3] + g_st[3]), 22);
	b->a = b->b + rl((b->a + md_f(b->b, b->c, b->d) + buff[4] + g_st[4]), 7);
	b->d = b->a + rl((b->d + md_f(b->a, b->b, b->c) + buff[5] + g_st[5]), 12);
	b->c = b->d + rl((b->c + md_f(b->d, b->a, b->b) + buff[6] + g_st[6]), 17);
	b->b = b->c + rl((b->b + md_f(b->c, b->d, b->a) + buff[7] + g_st[7]), 22);
	b->a = b->b + rl((b->a + md_f(b->b, b->c, b->d) + buff[8] + g_st[8]), 7);
	b->d = b->a + rl((b->d + md_f(b->a, b->b, b->c) + buff[9] + g_st[9]), 12);
	b->c = b->d + rl((b->c + md_f(b->d, b->a, b->b) + buff[10] + g_st[10]), 17);
	b->b = b->c + rl((b->b + md_f(b->c, b->d, b->a) + buff[11] + g_st[11]), 22);
	b->a = b->b + rl((b->a + md_f(b->b, b->c, b->d) + buff[12] + g_st[12]), 7);
	b->d = b->a + rl((b->d + md_f(b->a, b->b, b->c) + buff[13] + g_st[13]), 12);
	b->c = b->d + rl((b->c + md_f(b->d, b->a, b->b) + buff[14] + g_st[14]), 17);
	b->b = b->c + rl((b->b + md_f(b->c, b->d, b->a) + buff[15] + g_st[15]), 22);
}

void	md5_round_2(t_md_buffers *b, uint32_t *buff)
{
	b->a = b->b + rl((b->a + md_g(b->b, b->c, b->d) + buff[1] + g_st[16]), 5);
	b->d = b->a + rl((b->d + md_g(b->a, b->b, b->c) + buff[6] + g_st[17]), 9);
	b->c = b->d + rl((b->c + md_g(b->d, b->a, b->b) + buff[11] + g_st[18]), 14);
	b->b = b->c + rl((b->b + md_g(b->c, b->d, b->a) + buff[0] + g_st[19]), 20);
	b->a = b->b + rl((b->a + md_g(b->b, b->c, b->d) + buff[5] + g_st[20]), 5);
	b->d = b->a + rl((b->d + md_g(b->a, b->b, b->c) + buff[10] + g_st[21]), 9);
	b->c = b->d + rl((b->c + md_g(b->d, b->a, b->b) + buff[15] + g_st[22]), 14);
	b->b = b->c + rl((b->b + md_g(b->c, b->d, b->a) + buff[4] + g_st[23]), 20);
	b->a = b->b + rl((b->a + md_g(b->b, b->c, b->d) + buff[9] + g_st[24]), 5);
	b->d = b->a + rl((b->d + md_g(b->a, b->b, b->c) + buff[14] + g_st[25]), 9);
	b->c = b->d + rl((b->c + md_g(b->d, b->a, b->b) + buff[3] + g_st[26]), 14);
	b->b = b->c + rl((b->b + md_g(b->c, b->d, b->a) + buff[8] + g_st[27]), 20);
	b->a = b->b + rl((b->a + md_g(b->b, b->c, b->d) + buff[13] + g_st[28]), 5);
	b->d = b->a + rl((b->d + md_g(b->a, b->b, b->c) + buff[2] + g_st[29]), 9);
	b->c = b->d + rl((b->c + md_g(b->d, b->a, b->b) + buff[7] + g_st[30]), 14);
	b->b = b->c + rl((b->b + md_g(b->c, b->d, b->a) + buff[12] + g_st[31]), 20);
}

void	md5_round_3(t_md_buffers *b, uint32_t *buff)
{
	b->a = b->b + rl((b->a + md_h(b->b, b->c, b->d) + buff[5] + g_st[32]), 4);
	b->d = b->a + rl((b->d + md_h(b->a, b->b, b->c) + buff[8] + g_st[33]), 11);
	b->c = b->d + rl((b->c + md_h(b->d, b->a, b->b) + buff[11] + g_st[34]), 16);
	b->b = b->c + rl((b->b + md_h(b->c, b->d, b->a) + buff[14] + g_st[35]), 23);
	b->a = b->b + rl((b->a + md_h(b->b, b->c, b->d) + buff[1] + g_st[36]), 4);
	b->d = b->a + rl((b->d + md_h(b->a, b->b, b->c) + buff[4] + g_st[37]), 11);
	b->c = b->d + rl((b->c + md_h(b->d, b->a, b->b) + buff[7] + g_st[38]), 16);
	b->b = b->c + rl((b->b + md_h(b->c, b->d, b->a) + buff[10] + g_st[39]), 23);
	b->a = b->b + rl((b->a + md_h(b->b, b->c, b->d) + buff[13] + g_st[40]), 4);
	b->d = b->a + rl((b->d + md_h(b->a, b->b, b->c) + buff[0] + g_st[41]), 11);
	b->c = b->d + rl((b->c + md_h(b->d, b->a, b->b) + buff[3] + g_st[42]), 16);
	b->b = b->c + rl((b->b + md_h(b->c, b->d, b->a) + buff[6] + g_st[43]), 23);
	b->a = b->b + rl((b->a + md_h(b->b, b->c, b->d) + buff[9] + g_st[44]), 4);
	b->d = b->a + rl((b->d + md_h(b->a, b->b, b->c) + buff[12] + g_st[45]), 11);
	b->c = b->d + rl((b->c + md_h(b->d, b->a, b->b) + buff[15] + g_st[46]), 16);
	b->b = b->c + rl((b->b + md_h(b->c, b->d, b->a) + buff[2] + g_st[47]), 23);
}

void	md5_round_4(t_md_buffers *b, uint32_t *buff)
{
	b->a = b->b + rl((b->a + md_i(b->b, b->c, b->d) + buff[0] + g_st[48]), 6);
	b->d = b->a + rl((b->d + md_i(b->a, b->b, b->c) + buff[7] + g_st[49]), 10);
	b->c = b->d + rl((b->c + md_i(b->d, b->a, b->b) + buff[14] + g_st[50]), 15);
	b->b = b->c + rl((b->b + md_i(b->c, b->d, b->a) + buff[5] + g_st[51]), 21);
	b->a = b->b + rl((b->a + md_i(b->b, b->c, b->d) + buff[12] + g_st[52]), 6);
	b->d = b->a + rl((b->d + md_i(b->a, b->b, b->c) + buff[3] + g_st[53]), 10);
	b->c = b->d + rl((b->c + md_i(b->d, b->a, b->b) + buff[10] + g_st[54]), 15);
	b->b = b->c + rl((b->b + md_i(b->c, b->d, b->a) + buff[1] + g_st[55]), 21);
	b->a = b->b + rl((b->a + md_i(b->b, b->c, b->d) + buff[8] + g_st[56]), 6);
	b->d = b->a + rl((b->d + md_i(b->a, b->b, b->c) + buff[15] + g_st[57]), 10);
	b->c = b->d + rl((b->c + md_i(b->d, b->a, b->b) + buff[6] + g_st[58]), 15);
	b->b = b->c + rl((b->b + md_i(b->c, b->d, b->a) + buff[13] + g_st[59]), 21);
	b->a = b->b + rl((b->a + md_i(b->b, b->c, b->d) + buff[4] + g_st[60]), 6);
	b->d = b->a + rl((b->d + md_i(b->a, b->b, b->c) + buff[11] + g_st[61]), 10);
	b->c = b->d + rl((b->c + md_i(b->d, b->a, b->b) + buff[2] + g_st[62]), 15);
	b->b = b->c + rl((b->b + md_i(b->c, b->d, b->a) + buff[9] + g_st[63]), 21);
}

void	md5_rounds(t_md_buffers *md_buffs, uint32_t *x_buffer)
{
	int		i;
	static	void (*md5_rounds[MD5_NB_ROUNDS])(t_md_buffers *, uint32_t *) =
	{
		md5_round_1,
		md5_round_2,
		md5_round_3,
		md5_round_4
	};
	i = 0;
	while (i < MD5_NB_ROUNDS)
	{
		md5_rounds[i](md_buffs, x_buffer);
		i++;
	}
}
