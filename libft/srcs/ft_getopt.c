/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:52:49 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/04 14:52:49 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_opt_parser(t_opt_parser *parser, t_option *opts, size_t size)
{
	parser->options = opts;
	parser->nb_options = size;
}

void	print_number(int fd, int number)
{
	int mod;

	mod = number % 10;
	if (mod == 1)
		ft_dprintf(fd, "%dst", number);
	else if (mod == 2)
		ft_dprintf(fd, "%dnd", number);
	else
		ft_dprintf(fd, "%dth", number);
}

int		print_necessaries_options(t_opt_parser *parser, int index)
{
	size_t	i;
	size_t	j;

	print_number(2, index + 1);
	ft_dprintf(2, " argument has to be one of those:\n");
	i = 0;
	j = 0;
	while (i < parser->nb_options)
	{
		if (parser->options[i].fixed_position == index)
		{
			if (j++ == 0)
				ft_dprintf(2, "\n");
			dprint_option(2, &parser->options[i], 1);
			ft_dprintf(2, "\n");
		}
		i++;
	}
	ft_dprintf(2, "\n");
	return (E_OPT_RET_ERROR_UNKNOWN_OPTION);
}

int		describe_option(char *arg)
{
	return (ft_strlen(arg) >= 2 && arg[0] == '-');
}

int		process_option_list(t_opt_parser *parser, char ***argv, void *env)
{
	char	*arg;
	size_t	i;
	size_t	j;
	int		ret;

	arg = **argv;
	i = 1;
	while (arg[i])
	{
		j = 0;
		while (j < parser->nb_options)
		{
			if (parser->options[j].char_name == arg[i])
			{
				if (parser->options[j].argument != NULL && arg[i + 1])
				{
					ft_dprintf(2, "option -%c requires a following argument\n",
						arg[i]);
					return (E_OPT_RET_ERROR_NO_ARGUMENT);
				}
				if ((ret = parser->options[j].update(argv, env)))
					return (ret);
				break;
			}
			j++;
		}
		if (j >= parser->nb_options)
		{
			ft_dprintf(2, "-%c: unkown option\n", arg[i]);
			return (E_OPT_RET_ERROR_UNKNOWN_OPTION);
		}
		i++;
	}
	return (0);
}

int await_necessary_options(t_opt_parser *parser, int index)
{
	size_t i;

	i = 0;
	while (i < parser->nb_options)
	{
		if (parser->options[i].necessity > 0
			&& parser->options[i].fixed_position != -1
			&& parser->options[i].fixed_position > index)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int		process_arg(int index, char ***argv, t_opt_parser *parser, void *env)
{
	size_t	i;
	size_t	j;
	int		necessity;

	i = 0;
	while (i < parser->nb_options)
	{
		if (parser->options[i].fixed_position == index
			&& (necessity = parser->options[i].necessity) > 0)
		{
			j = i;
			while (j < parser->nb_options)
			{
				if (ft_match_position(&parser->options[j], index)
					&& parser->options[j].necessity == necessity
					&& ft_match_arg(&parser->options[j], **argv))
				{
					return (parser->options[j].update(argv, env));
				}
				j++;
			}
			if (j == parser->nb_options)
				return (print_necessaries_options(parser, index));
		}
		else if (ft_match_position(&parser->options[i], index)
			&& ft_match_arg(&parser->options[i], **argv))
			return (parser->options[i].update(argv, env));
		i++;
	}
	if (describe_option(**argv))
		return (process_option_list(parser, argv, env));
	if (await_necessary_options(parser, index))
	{
		ft_dprintf(2, "%s: unknown option\n", **argv);
		return (E_OPT_RET_ERROR_UNKNOWN_OPTION);
	}
	return (E_OPT_RET_END_OF_PARSING);
}

int		ft_need_option(t_opt_parser *parser)
{
	size_t i;

	i = 0;
	while (i < parser->nb_options)
	{
		if (parser->options[i++].necessity > 0)
			return (1);
	}
	return (0);
}

int		ft_getopt(char ***argv, t_opt_parser *parser, void *env)
{
	char	**argv_save;
	int		ret;
	int		parsed_options;

	parsed_options = 0;
	parser->progname = (*argv)[0];
	(*argv)++;
	argv_save = *argv;
	while (**argv)
	{
		if (!ft_strcmp("--", **argv))
		{
			parsed_options = *argv - argv_save;
			(*argv)++;
			break;
		}
		if ((ret = process_arg(*argv - argv_save, argv, parser, env)))
		{
			if (ret == E_OPT_RET_ERROR_UNKNOWN_OPTION
				|| ret == E_OPT_RET_ERROR_NO_ARGUMENT)
				print_usage(parser);
			return (ret == E_OPT_RET_END_OF_PARSING ? 0 : ret);
		}
		(*argv)++;
		parsed_options = *argv - argv_save;
	}
	if (await_necessary_options(parser, parsed_options - 1))
	{
		print_usage(parser);
		return (E_OPT_RET_ERROR_NO_OPTIONS);
	}
	return (0);
}
