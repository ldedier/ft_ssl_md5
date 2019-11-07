/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:00:48 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/07 19:00:48 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;


	uint32_t a = 5;
	uint32_t b = UINT_MAX;

	printf("%u\n", (uint32_t)pow(2, 32) - 1);
	printf("%u\n", UINT_MAX);

	printf("%d\n", b + 1);
	
	return (0);
}
