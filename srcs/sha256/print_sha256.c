/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sha256.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 02:29:03 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/27 13:44:28 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	print_sha(t_sha256 *sha)
{
	ft_printf("word h0 = %.8x\n", sha->h0);
	ft_printf("word h1 = %.8x\n", sha->h1);
	ft_printf("word h2 = %.8x\n", sha->h2);
	ft_printf("word h3 = %.8x\n", sha->h3);
	ft_printf("word h4 = %.8x\n", sha->h4);
	ft_printf("word h5 = %.8x\n", sha->h5);
	ft_printf("word h6 = %.8x\n", sha->h6);
	ft_printf("word h7 = %.8x\n", sha->h7);
}

void	print_sha_variables(t_sha256 *sha)
{
	ft_printf("word a = %.8x\n", sha->a);
	ft_printf("word b = %.8x\n", sha->b);
	ft_printf("word c = %.8x\n", sha->c);
	ft_printf("word d = %.8x\n", sha->d);
	ft_printf("word e = %.8x\n", sha->e);
	ft_printf("word f = %.8x\n", sha->f);
	ft_printf("word g = %.8x\n", sha->g);
	ft_printf("word h = %.8x\n", sha->h);
}

void	print_sha_int(t_sha256 *sha)
{
	ft_printf("word h0 = %d\n", sha->h0);
	ft_printf("word h1 = %d\n", sha->h1);
	ft_printf("word h2 = %d\n", sha->h2);
	ft_printf("word h3 = %d\n", sha->h3);
	ft_printf("word h4 = %d\n", sha->h4);
	ft_printf("word h5 = %d\n", sha->h5);
	ft_printf("word h6 = %d\n", sha->h6);
	ft_printf("word h7 = %d\n", sha->h7);
}
