/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:54:59 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/06 15:54:59 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"
#include <math.h>

uint32_t	md_f(uint32_t x, uint32_t y, uint32_t z)
{
	return (x & y) | (~x & z);
}

uint32_t	md_g(uint32_t x, uint32_t y, uint32_t z)
{
	return (x & z) | (y & ~z);
}

uint32_t	md_h(uint32_t x, uint32_t y, uint32_t z)
{
	return (x ^ y ^ z);
}

uint32_t	md_i(uint32_t x, uint32_t y, uint32_t z)
{
	return (y ^ (x | ~z));
}
