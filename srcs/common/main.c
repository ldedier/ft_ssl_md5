/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:48:52 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/28 11:43:19 by ldedier          ###   ########.fr       */
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
	{-1, NULL, "sha384", NULL, ft_ssl_parse_sha384,
		"hash following the sha-384 protocol", 0, 1},
	{-1, NULL, "sha512", NULL, ft_ssl_parse_sha512,
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

int		init_ssl_from_options(char ***argv, t_opt_parser *parser, t_ssl *ssl)
{
	int ret;

	init_ssl(ssl);
	if ((ret = ft_getopt(argv, parser, ssl)))
	{
		if (ret == E_OPT_RET_ERROR_FATAL)
			ft_dprintf(2, "fatal error\n");
		return (E_EXIT_FAILURE);
	}
	return (E_EXIT_SUCCESS);
}

int		ft_ssl(char **argv, t_opt_parser *parser, int recursive)
{
	t_ssl	ssl;

	if (init_ssl_from_options(&argv, parser, &ssl))
		return (E_EXIT_ERROR);
	return (parse_args(argv, parser, &ssl, recursive));
}

int		main(int argc, char **argv)
{
	t_opt_parser	parser;

	(void)argc;
	init_opt_parser(&parser, g_opts, sizeof(g_opts) / sizeof(t_option), 0);
	parser.progname = argv[0];
	return (ft_ssl(argv + 1, &parser, 1) == 0 ? 0 : 1);
}
