/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:48:52 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/04 14:48:52 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static t_option g_opts[SSL_NB_OPTIONS] =
{
	{-1, NULL, "md5", NULL, ft_ssl_parse_md5,
		"hash following the md5 protocol", 0, 1},
	{-1, NULL, "sha256", NULL, ft_ssl_parse_sha256,
		"hash following the sha-256 protocol", 0, 1},
	{-1, NULL, "sha224", NULL, ft_ssl_parse_sha224,
		"hash following the sha-224 protocol", 0, 1},
	{-1, NULL, "sha512", NULL, ft_ssl_parse_sha224,
		"hash following the sha-512 protocol", 0, 1},
	{'p', NULL, NULL, NULL, ft_ssl_parse_p,
		"echo stdin to stdout and append the checksum to stdout", -1, 0},
	{'q', NULL, NULL, NULL, ft_ssl_parse_q, "quiet mode", -1, -1},
	{'r', NULL, NULL, NULL, ft_ssl_parse_r, "reverse output format", -1, 0},
	{'s', NULL, NULL, "\"string_to_hash\"", ft_ssl_parse_s,
		"print the sum of the given string", -1, 0}
};

void	init_ssl(t_ssl *ssl)
{
	ssl->opt_p = 0;
	ssl->opt_n = 0;
	ssl->opt_r = 0;
	ssl->opt_q = 0;
	ssl->opt_s = 0;
	ssl->hash.name = NULL;
	ssl->hash.id = -1;
}

int main(int argc, char **argv)
{
	t_opt_parser	parser;
	t_ssl			ssl;

	(void)argc;
	init_ssl(&ssl);
	init_opt_parser(&parser, g_opts, sizeof(g_opts) / sizeof(t_option));
	if (ft_getopt(&argv, &parser, &ssl))
		return (1);
	return (parse_args(argv, &ssl));
}
