/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:12:54 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/05 20:12:54 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_opt_ret	ft_ssl_parse_md5(char ***argv, void *s)
{
	t_ssl *ssl;

	ssl = (t_ssl *)s;
	ssl->hash.id = E_HASH_ID_MD5;
	ssl->hash.name = **argv;
	return (E_OPT_RET_OK);
}

t_opt_ret	ft_ssl_parse_sha256(char ***argv, void *s)
{
	t_ssl *ssl;

	ssl = (t_ssl *)s;
	ssl->hash.id = E_HASH_ID_SHA256;
	ssl->hash.name = **argv;
	return (E_OPT_RET_OK);
}

t_opt_ret	ft_ssl_parse_sha224(char ***argv, void *s)
{
	t_ssl *ssl;

	ssl = (t_ssl *)s;
	ssl->hash.id = E_HASH_ID_SHA224;
	ssl->hash.name = **argv;
	return (E_OPT_RET_OK);
}

t_opt_ret	ft_ssl_parse_sha384(char ***argv, void *s)
{
	t_ssl *ssl;

	ssl = (t_ssl *)s;
	ssl->hash.id = E_HASH_ID_SHA384;
	ssl->hash.name = **argv;
	return (E_OPT_RET_OK);
}

t_opt_ret	ft_ssl_parse_sha512(char ***argv, void *s)
{
	t_ssl *ssl;

	ssl = (t_ssl *)s;
	ssl->hash.id = E_HASH_ID_SHA512;
	ssl->hash.name = **argv;
	return (E_OPT_RET_OK);
}
