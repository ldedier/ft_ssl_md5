/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_1024.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:04:28 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/27 18:24:20 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <stdint.h>

int		pad_input_1024(unsigned char **input, size_t *size, int should_swap)
{
	unsigned char		*res;
	int					congruence;
	int					to_add;
	__uint128_t			bit_size;

	bit_size = *size * 8;
	swap_bytes(&bit_size, sizeof(bit_size), should_swap);
	congruence = (*size * sizeof(unsigned char) * 8) % 1024;
	to_add = (1024 - 128) - congruence;
	if (to_add <= 0)
		to_add += 1024;
	to_add /= (sizeof(unsigned char) * 8);
	if (!(res = (unsigned char *)malloc(sizeof(unsigned char)
					* (*size + to_add + sizeof(bit_size)))))
	{
		return (1);
	}
	ft_memcpy(res, *input, *size);
	ft_bzero(res + *size, to_add + sizeof(bit_size));
	res[*size] = 0b10000000;
	ft_memcpy(res + *size + to_add, &bit_size, sizeof(bit_size));
	free(*input);
	*input = res;
	*size += to_add + sizeof(bit_size);
	return (0);
}
