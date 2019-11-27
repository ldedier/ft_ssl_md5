/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:14:12 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/27 18:40:12 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <string.h>
#include <errno.h>

static char	*(*g_hashes[NB_HASHES])(unsigned char **, size_t) =
{
	ft_hash_md5,
	ft_hash_sha256,
	ft_hash_sha224,
	ft_hash_sha384,
	ft_hash_sha512,
};

char		*hash(unsigned char **input, size_t size, int id)
{
	return (g_hashes[id](input, size));
}

int			get_input_from_file(t_ssl *ssl, char **input,
			size_t *size, char *filename)
{
	int		fd;
	char	*error;

	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		error = strerror(errno);
		ft_dprintf(2, "ft_ssl: %s: %s: %s\n", ssl->hash.name, filename, error);
		return (1);
	}
	if (!(*input = get_file_as_string(fd, size)))
	{
		ft_dprintf(2, "fatal error\n");
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

char		*get_input(t_ssl *ssl, char *to_hash,
			t_hash_content content, size_t *size)
{
	char	*input;

	if (content == E_HASH_CONTENT_STRING)
	{
		if (!(input = ft_strdup(to_hash)))
		{
			ft_dprintf(2, "fatal error\n");
			return (NULL);
		}
		*size = ft_strlen(to_hash);
	}
	else if (content == E_HASH_CONTENT_FILENAME)
	{
		if (get_input_from_file(ssl, &input, size, to_hash))
			return (NULL);
	}
	else
	{
		if (!(input = get_file_as_string(STDIN_FILENO, size)))
		{
			ft_dprintf(2, "fatal error\n");
			return (NULL);
		}
	}
	return (input);
}

char		*get_hash(t_ssl *ssl, char *to_hash,
			t_hash_content content, int print_input)
{
	char	*input;
	size_t	size;
	char	*res;

	if (!(input = get_input(ssl, to_hash, content, &size)))
	{
		return (NULL);
	}
	if (print_input)
		write(1, input, size);
	res = hash((unsigned char **)&input, size, ssl->hash.id);
	free(input);
	return (res);
}
