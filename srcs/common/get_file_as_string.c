/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_as_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:09:50 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/27 14:12:19 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_memjoin_free(char *first, size_t fsize,
				char *second, size_t ssize)
{
	char *res;

	if (!(res = (char *)malloc(fsize + ssize)))
	{
		free(first);
		return (NULL);
	}
	ft_memcpy(res, first, fsize);
	ft_memcpy(res + fsize, second, ssize);
	free(first);
	return (res);
}

char		*get_file_as_string(int fd, size_t *size)
{
	char	buffer[4096];
	int		ret;
	char	*res;

	*size = 0;
	if (!(res = ft_strnew(0)))
		return (NULL);
	while ((ret = read(fd, buffer, 4096)) > 0)
	{
		if (!(res = ft_memjoin_free(res, *size, buffer, ret)))
			return (NULL);
		*size += ret;
	}
	if (ret < 0)
	{
		free(res);
		return (NULL);
	}
	return (res);
}
