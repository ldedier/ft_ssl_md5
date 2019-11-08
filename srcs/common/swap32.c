/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap32.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 16:15:03 by ldedier           #+#    #+#             */
/*   Updated: 2019/08/15 16:19:09 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	swap_bytes(void *to_swap, size_t size, int should_swap)
{
	size_t          i;
	char            tmp;
	unsigned char   *array;

	if (should_swap)
	{
		array = (unsigned char *)to_swap;
		i = 0;
		while (i < size / 2)
		{
			tmp = array[i];
			array[i] = array[size - i - 1];
			array[size - i - 1] = tmp;
			i++;
		}
	}
}

void	swap_uint32(uint32_t *value)
{
	*value = ((((*value) & 0xff000000) >> 24)
		| (((*value) & 0xff0000) >> 8) | (((*value) & 0xff00) << 8)
			| (((*value) & 0xff) << 24));
}
