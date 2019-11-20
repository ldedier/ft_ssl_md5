/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:59:11 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/19 22:43:11 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		process_interactive_input(char *input,
			t_opt_parser *parser, int *run)
{
	char **split;

	if (!(split = ft_split_whitespace(input)))
		return (E_EXIT_FAILURE);
	if (split[0] && !ft_strcmp(split[0], "exit"))
	{
		*run = 0;
		ft_free_split(split);
		return (E_EXIT_SUCCESS);
	}
	if (ft_ssl(split, parser, 0) == E_EXIT_FAILURE)
	{
		ft_free_split(split);
		return (E_EXIT_FAILURE);
	}
	ft_free_split(split);
	return (E_EXIT_SUCCESS);
}

int		ssl_interactive(t_ssl *ssl, t_opt_parser *parser)
{
	t_gnl_info	info;
	int			ret;
	int			run;

	(void)ssl;
	run = 1;
	while (run)
	{
		ft_printf("%s%s%s ", CYAN, SSL_PROMPT, EOC);
		if ((ret = get_next_line2(0, &info)) > 0)
		{
			if (info.separator == E_SEPARATOR_ZERO)
				return (ft_free_turn(info.line, E_EXIT_FAILURE));
			else if (info.separator == E_SEPARATOR_NL)
			{
				if ((ret = process_interactive_input(info.line, parser, &run)))
					return (ft_free_turn(info.line, E_EXIT_FAILURE));
			}
			else
			{
				if ((ret = process_interactive_input(info.line, parser, &run)))
					return (ft_free_turn(info.line, E_EXIT_FAILURE));
				return (ft_free_turn(info.line, E_EXIT_SUCCESS));
			}
		}
		else
		{
			if (ret == -1)
				return (E_EXIT_FAILURE);
			run = 0;
		}
		free(info.line);
	}
	return (E_EXIT_SUCCESS);
}
