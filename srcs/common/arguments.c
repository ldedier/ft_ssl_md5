/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:14:22 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/05 20:14:22 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		parse_args(char **argv, t_ssl *ssl)
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
	if (argv == argv_save && !ssl->opt_p && !ssl->opt_s)
		return (ssl_hash(ssl, *argv, E_HASH_CONTENT_STDIN, 0));
	return (EXIT_SUCCESS);
}
