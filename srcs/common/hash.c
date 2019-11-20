/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:44:13 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/05 16:44:13 by ldedier          ###   ########.fr       */
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

char		*ft_memjoin_free(char *first, size_t fsize,
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

int		get_input_from_file(t_ssl *ssl, char **input,
			size_t *size, char *filename)
{
	int		fd;
	char	*error;

	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		error = strerror(errno);
		ft_dprintf(2, "ft_ssl: %s: %s: %s\n",
				ssl->hash.name, filename, error);
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

char	*get_hash(t_ssl *ssl, char *to_hash,
			t_hash_content content, int print_input)
{
	char	*input;
	size_t	size;
	char	*res;

	if (content == E_HASH_CONTENT_STRING)
	{
		if (!(input = ft_strdup(to_hash)))
		{
			ft_dprintf(2, "fatal error\n");
			return (NULL);
		}
		size = ft_strlen(to_hash);
	}
	else if (content == E_HASH_CONTENT_FILENAME)
	{
		if (get_input_from_file(ssl, &input, &size, to_hash))
			return (NULL);
	}
	else
	{
		if (!(input = get_file_as_string(STDIN_FILENO, &size)))
		{
			ft_dprintf(2, "fatal error\n");
			return (NULL);
		}
	}
	if (print_input)
		write(1, input, size);
	res = hash((unsigned char **)&input, size, ssl->hash.id);
	free(input);
	return (res);
}

void		ft_print_maj(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_printf("%c", ft_toupper(str[i]));
		i++;
	}
}

int 		ssl_hash(t_ssl *ssl, char *to_hash,
	t_hash_content content, int print_input)
{
	char *result;

	if (!(result = get_hash(ssl, to_hash, content, print_input)))
		return (1);
	if (content != E_HASH_CONTENT_STDIN && !ssl->opt_q && !ssl->opt_r)
	{
		ft_print_maj(ssl->hash.name);
		if (content == E_HASH_CONTENT_STRING)
			ft_printf("(\"%s\") = ", to_hash);
		else if (content == E_HASH_CONTENT_FILENAME)
			ft_printf("(%s)= ", to_hash);
	}
	ft_printf("%s", result);
	if (content != E_HASH_CONTENT_STDIN && !ssl->opt_q && ssl->opt_r)
	{
		if (content == E_HASH_CONTENT_STRING)
			ft_printf(" \"%s\"", to_hash);
		else if (content == E_HASH_CONTENT_FILENAME)
			ft_printf(" %s", to_hash);
	}
	ft_printf("\n");
	free(result);
	return (0);
}
