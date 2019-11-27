/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:57:44 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/27 13:58:25 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	debug_input_int(const unsigned char *input, size_t size)
{
	size_t			i;
	unsigned int	*ptr;

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
	size_t			i;
	unsigned int	*ptr;

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
