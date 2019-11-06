/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:10:17 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/05 17:10:17 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"
#include <math.h>

uint64_t g_st[64] = 
{
	3614090360,
	3905402710,
	606105819,
	3250441966,
	4118548399,
	1200080426,
	2821735955,
	4249261313,
	1770035416,
	2336552879,
	4294925233,
	2304563134,
	1804603682,
	4254626195,
	2792965006,
	1236535329,
	4129170786,
	3225465664,
	643717713,
	3921069994,
	3593408605,
	38016083,
	3634488961,
	3889429448,
	568446438,
	3275163606,
	4107603335,
	1163531501,
	2850285829,
	4243563512,
	1735328473,
	2368359562,
	4294588738,
	2272392833,
	1839030562,
	4259657740,
	2763975236,
	1272893353,
	4139469664,
	3200236656,
	681279174,
	3936430074,
	3572445317,
	76029189,
	3654602809,
	3873151461,
	530742520,
	3299628645,
	4096336452,
	1126891415,
	2878612391,
	4237533241,
	1700485571,
	2399980690,
	4293915773,
	2240044497,
	1873313359,
	4264355552,
	2734768916,
	1309151649,
	4149444226,
	3174756917,
	718787259,
	3951481745
};

void	debug_input_int(const unsigned char *input, size_t size)
{
	size_t i;

	unsigned int *ptr;

	ptr = (unsigned int *)input;

	
	ft_printf("size: %d\n", size * 8);
	i = 0;
	while (i < size / 4)
	{
		ft_printf("%d: %u\n", i, ptr[i]);
		i++;
	}
	ft_printf("\n");
}

void	debug_input(const unsigned char *input, size_t size)
{
	size_t i;

	ft_printf("size: %d\n", size * 8);
	i = 0;
	while (i < size)
	{
		ft_printf("%.8b", input[i]);
		if (++i < size)
			ft_printf(", ");
	}
	ft_printf("\n");
}

static	int	pad_input(unsigned char **input, size_t *size)
{
	unsigned char	*res;
	int				congruence;
	int				to_add;
	uint64_t		bit_size;

	bit_size = *size * 8;
	congruence = (*size * sizeof(unsigned char) * 8) % 512;
	to_add = 448 - congruence;
	if (to_add <= 0)
		to_add += 512;
	to_add /= (sizeof(unsigned char) * 8);
	if (!(res = (unsigned char *)malloc(sizeof(unsigned char)
		* (*size + to_add + 8))))
	{
		return (1);
	}
	ft_memcpy(res, *input, *size);
	ft_bzero(res + *size, to_add + 8);
	res[*size] = 0b10000000;
	ft_memcpy(res + *size + to_add, &bit_size, 8);
	free(*input);
	*input = res;
	*size += to_add + 8;
	return (0);
}

char	*ft_hash_md5_message(t_md5 *md5, unsigned char *input, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	nb_words;
	uint32_t *words;
	uint32_t x_buffer[16];

	nb_words = size / sizeof(uint32_t);
	words = (uint32_t *)input;
	i = 0;
	while (i < nb_words)
	{
		j = 0;
		while (j < 16)
		{
			x_buffer[j] = words[i + j];
			j++;
		}
		save_buffs(&md5->buffs);
		md5_rounds(&md5->buffs, x_buffer);
		append_buffs(&md5->buffs);
		i += 16;
	}
//	ft_printf("\nRESULT BUFFERS: \n\n");
//	print_buffers(&md5->buffs);
	return (generate_hash_from_buffers(&md5->buffs));
}

char *ft_hash_md5(unsigned char *input, size_t size)
{
	t_md5			md5;

	init_md_buffers(&md5.buffs);
	if (pad_input(&input, &size))
		return (NULL);
//	debug_input_int(input, size);
//	ft_printf("\n");
//	print_buffers_int(&md5.buffs);
	return (ft_hash_md5_message(&md5, input, size));
}
