/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_sha224.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 02:57:17 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/08 02:57:17 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char	*ft_hash_sha224(unsigned char *input, size_t size)
{
	t_sha256  sha;

	init_sha224(&sha);
	if (pad_input_512(&input, &size, 1))
		return (NULL);
	return (ft_hash_sha256_message(&sha, input, size, 7));
}
