/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sha512.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 21:17:50 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/27 13:49:07 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	print_sha512(t_sha512 *sha)
{
	ft_printf("word h0 = %.16x\n", sha->h0);
	ft_printf("word h1 = %.16x\n", sha->h1);
	ft_printf("word h2 = %.16x\n", sha->h2);
	ft_printf("word h3 = %.16x\n", sha->h3);
	ft_printf("word h4 = %.16x\n", sha->h4);
	ft_printf("word h5 = %.16x\n", sha->h5);
	ft_printf("word h6 = %.16x\n", sha->h6);
	ft_printf("word h7 = %.16x\n", sha->h7);
}

void	print_sha512_variables(t_sha512 *sha)
{
	ft_printf("word a = %.16x\n", sha->a);
	ft_printf("word b = %.16x\n", sha->b);
	ft_printf("word c = %.16x\n", sha->c);
	ft_printf("word d = %.16x\n", sha->d);
	ft_printf("word e = %.16x\n", sha->e);
	ft_printf("word f = %.16x\n", sha->f);
	ft_printf("word g = %.16x\n", sha->g);
	ft_printf("word h = %.16x\n", sha->h);
}

void	print_sha512_int(t_sha512 *sha)
{
	ft_printf("word h0 = %lld\n", sha->h0);
	ft_printf("word h1 = %lld\n", sha->h1);
	ft_printf("word h2 = %lld\n", sha->h2);
	ft_printf("word h3 = %lld\n", sha->h3);
	ft_printf("word h4 = %lld\n", sha->h4);
	ft_printf("word h5 = %lld\n", sha->h5);
	ft_printf("word h6 = %lld\n", sha->h6);
	ft_printf("word h7 = %lld\n", sha->h7);
}
