/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:26:10 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/07 21:07:59 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t rl(uint32_t val, int n)
{
	return ((val << n) | (val >> (32 - n)));
}

uint32_t rr(uint32_t val, int n)
{
	return ((val >> n) | (val << (32 - n)));
}

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

void	debug_input_hex(const unsigned char *input, size_t size)
{
	size_t i;

	unsigned int *ptr;
	ptr = (unsigned int *)input;

	ft_printf("size: %d\n", size * 8);
	i = 0;
	while (i < size / 4)
	{
		ft_printf("%d: %08x\n", i, ptr[i]);
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
