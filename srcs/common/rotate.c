/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:56:54 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/27 13:57:05 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t	rl(uint32_t val, int n)
{
	return ((val << n) | (val >> (32 - n)));
}

uint32_t	rr(uint32_t val, int n)
{
	return ((val >> n) | (val << (32 - n)));
}

uint64_t	rl64(uint64_t val, int n)
{
	return ((val << n) | (val >> (64 - n)));
}

uint64_t	rr64(uint64_t val, int n)
{
	return ((val >> n) | (val << (64 - n)));
}
