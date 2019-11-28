/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:14:22 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/28 11:56:19 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		parse_args(char **argv, t_opt_parser *parser, t_ssl *ssl, int recursive)
{
	char	**argv_save;
	int		ret;
	int		tmp;

	ret = 0;
	argv_save = argv;
	while (*argv)
	{
		if ((tmp = ssl_hash(ssl, *argv, E_HASH_CONTENT_FILENAME, 0)) ==
			E_OPT_RET_ERROR_FATAL)
			return (E_OPT_RET_ERROR_FATAL);
		ret |= tmp;
		argv++;
	}
	if (argv == argv_save)
	{
		if ((int)ssl->hash.id != -1
			&& !ssl->opt_p && !ssl->opt_s && !ssl->opt_q && !ssl->opt_r)
			return (ssl_hash(ssl, NULL, E_HASH_CONTENT_STDIN, 0));
		else if ((int)ssl->hash.id == -1 && recursive)
			return (ssl_interactive(ssl, parser));
		else
			return (E_EXIT_SUCCESS);
	}
	return (ret);
}
