/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_hash_from_buffers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 01:10:39 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/07 01:10:39 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

static void		append_md5_buffer(char *str, uint32_t buffer)
{
	unsigned char *ptr;

	ptr = (unsigned char *)&buffer;
	ft_sprintf(str, "%.2hhx", *ptr);
	ft_sprintf(str + 2, "%.2hhx", *(ptr + 1));
	ft_sprintf(str + 4, "%.2hhx", *(ptr + 2));
	ft_sprintf(str + 6, "%.2hhx", *(ptr + 3));
}

char			*generate_hash_from_buffers(t_md_buffers *buffers)
{
	char *str;

	if (!(str = ft_strnew(32)))
		return (NULL);
	append_md5_buffer(str, buffers->a);
	append_md5_buffer(str + 8, buffers->b);
	append_md5_buffer(str + 16, buffers->c);
	append_md5_buffer(str + 24, buffers->d);
	return (str);
}
