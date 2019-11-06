/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_buffers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:56:15 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/06 15:56:15 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"
#include <math.h>

void	print_buffers(t_md_buffers *buffers)
{
	ft_printf("word A = %.8x\n", buffers->a);
	ft_printf("word B = %.8x\n", buffers->b);
	ft_printf("word C = %.8x\n", buffers->c);
	ft_printf("word D = %.8x\n", buffers->d);
}

void	print_buffers_int(t_md_buffers *buffers)
{
	ft_printf("word A = %u\n", buffers->a);
	ft_printf("word B = %u\n", buffers->b);
	ft_printf("word C = %u\n", buffers->c);
	ft_printf("word D = %u\n", buffers->d);
}

void	init_md_buffers(t_md_buffers *buffers)
{
	buffers->a = 0x67452301;
	buffers->b = 0xefcdab89;
	buffers->c = 0x98badcfe;
	buffers->d = 0x10325476;
}

void	save_buffs(t_md_buffers *buffers)
{
	buffers->aa = buffers->a;
	buffers->bb = buffers->b;
	buffers->cc = buffers->c;
	buffers->dd = buffers->d;
}

void	append_buffs(t_md_buffers *buffers)
{
	buffers->a = buffers->a + buffers->aa;
	buffers->b = buffers->b + buffers->bb;
	buffers->c = buffers->c + buffers->cc;
	buffers->d = buffers->d + buffers->dd;
}

void		append_md5_buffer(char *str, uint32_t buffer)
{
	unsigned char *ptr;

	ptr = (unsigned char *)&buffer;
	ft_sprintf(str, "%.2hhx", *ptr);
	ft_sprintf(str + 2, "%.2hhx", *(ptr + 1));
	ft_sprintf(str + 4, "%.2hhx", *(ptr + 2));
	ft_sprintf(str + 6, "%.2hhx", *(ptr + 3));
}

char	*generate_hash_from_buffers(t_md_buffers *buffers)
{
	char *str;

	if (!(str = ft_strnew(32)))
		return (NULL);
	append_md5_buffer(str, buffers->a);
	append_md5_buffer(str + 8, buffers->b);
	append_md5_buffer(str + 16, buffers->c);
	append_md5_buffer(str + 24, buffers->d);
	return (str);
}
