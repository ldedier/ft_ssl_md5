/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:44:13 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/28 12:00:57 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		ft_print_maj(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_printf("%c", ft_toupper(str[i]));
		i++;
	}
}

int				ssl_hash(t_ssl *ssl, char *to_hash,
	t_hash_content content, int print_input)
{
	char *result;

	if (!(result = get_hash(ssl, to_hash, content, print_input)))
		return (1);
	if (content != E_HASH_CONTENT_STDIN && !ssl->opt_q && !ssl->opt_r)
	{
		ft_print_maj(ssl->hash.name);
		if (content == E_HASH_CONTENT_STRING)
			ft_printf(" (\"%s\") = ", to_hash);
		else if (content == E_HASH_CONTENT_FILENAME)
			ft_printf(" (%s) = ", to_hash);
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
