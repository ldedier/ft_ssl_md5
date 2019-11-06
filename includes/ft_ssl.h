/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:48:31 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/04 14:48:31 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "libft.h"
# include "ft_md5.h"
# include "ft_sha256.h"
# include <fcntl.h>

typedef enum		e_hash_content
{
	E_HASH_CONTENT_STRING,
	E_HASH_CONTENT_FILENAME,
	E_HASH_CONTENT_STDIN
}					t_hash_content;

typedef enum		e_hash_id
{
	E_HASH_ID_MD5,
	E_HASH_ID_SHA256,
	NB_HASHES
}					t_hash_id;

typedef struct		s_hash
{
	t_hash_id		id;
	char			*name;

}					t_hash;

typedef struct		s_ssl
{
	t_hash			hash;
	int				opt_p : 1;
	int				opt_n : 1;
	int				opt_q : 1;
	int				opt_r : 1;
	int				opt_s : 1;
}					t_ssl;

typedef char *(t_hash_func)(char *);

t_opt_ret		ft_ssl_parse_md5(char ***argv, void *w);
t_opt_ret		ft_ssl_parse_sha256(char ***argv, void *w);
t_opt_ret		ft_ssl_parse_p(char ***argv, void *w);
t_opt_ret		ft_ssl_parse_q(char ***argv, void *w);
t_opt_ret		ft_ssl_parse_r(char ***argv, void *w);
t_opt_ret		ft_ssl_parse_s(char ***argv, void *w);
int				ssl_hash(t_ssl *ssl, char *to_hash,
					t_hash_content content, int print_input);
int		parse_args(char **argv, t_ssl *ssl);
#endif
