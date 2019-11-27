/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_512.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:04:04 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/27 14:04:20 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		pad_input_512(unsigned char **input, size_t *size, int should_swap)
{
	unsigned char	*res;
	int				congruence;
	int				to_add;
	uint64_t		bit_size;

	bit_size = *size * 8;
	swap_bytes(&bit_size, sizeof(uint64_t), should_swap);
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
