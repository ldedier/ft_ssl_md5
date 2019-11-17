/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_sha384.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 21:51:55 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/10 21:51:55 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char *ft_hash_sha384(unsigned char *input, size_t size)
{
	t_sha512  sha;

	init_sha384(&sha);
	if (pad_input_1024(&input, &size, 1))
		return (NULL);
	return (ft_hash_sha512_message(&sha, input, size, 6));
}
