/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:13:17 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/26 10:49:40 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_opt_ret	ft_ssl_parse_p(char ***argv, void *s)
{
	t_ssl *ssl;

	(void)argv;
	ssl = (t_ssl *)s;
	ssl->opt_p = 1;
	if (ssl_hash(ssl, NULL, E_HASH_CONTENT_STDIN, 1))
		return (E_OPT_RET_ERROR_FATAL);
	return (E_OPT_RET_OK);
}

t_opt_ret	ft_ssl_parse_q(char ***argv, void *s)
{
	t_ssl *ssl;

	(void)argv;
	ssl = (t_ssl *)s;
	ssl->opt_q = 1;
	return (E_OPT_RET_OK);
}

t_opt_ret	ft_ssl_parse_r(char ***argv, void *s)
{
	t_ssl *ssl;

	(void)argv;
	ssl = (t_ssl *)s;
	(void)s;
	ssl->opt_r = 1;
	return (E_OPT_RET_OK);
}

t_opt_ret	ft_ssl_parse_s(char ***argv, void *s)
{
	t_ssl	*ssl;
	char	*string;

	ssl = (t_ssl *)s;
	(*argv)++;
	ssl->opt_s = 1;
	if (!(string = **argv))
	{
		ft_dprintf(2, "option -s requires a following argument\n");
		return (E_OPT_RET_ERROR_NO_ARGUMENT);
	}
	else
	{
		if (ssl_hash(ssl, string, E_HASH_CONTENT_STRING, 0))
			return (E_OPT_RET_ERROR_FATAL);
	}
	return (E_OPT_RET_OK);
}
