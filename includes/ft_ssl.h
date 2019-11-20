/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:48:31 by ldedier           #+#    #+#             */
/*   Updated: 2019/11/19 22:44:06 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "libft.h"
# include "ft_md5.h"
# include "ft_sha256.h"
# include "ft_sha512.h"
# include <fcntl.h>

# define SSL_NB_OPTIONS	9
# define SSL_PROMPT		"ft_ssl>"

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
	E_HASH_ID_SHA224,
	E_HASH_ID_SHA384,
	E_HASH_ID_SHA512,
	NB_HASHES
}					t_hash_id;

typedef enum		e_exit
{
	E_EXIT_SUCCESS,
	E_EXIT_ERROR,
	E_EXIT_FAILURE,
}					t_exit;

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
t_opt_ret		ft_ssl_parse_sha224(char ***argv, void *w);
t_opt_ret		ft_ssl_parse_sha384(char ***argv, void *w);
t_opt_ret		ft_ssl_parse_sha512(char ***argv, void *w);

t_opt_ret		ft_ssl_parse_p(char ***argv, void *w);
t_opt_ret		ft_ssl_parse_q(char ***argv, void *w);
t_opt_ret		ft_ssl_parse_r(char ***argv, void *w);
t_opt_ret		ft_ssl_parse_s(char ***argv, void *w);

int				ft_ssl(char **argv, t_opt_parser *parser, int recursive);
int				ssl_hash(t_ssl *ssl, char *to_hash,
				t_hash_content content, int print_input);
int				parse_args(char **argv, t_opt_parser *parser,
					t_ssl *ssl, int recursive);
int				pad_input_512(unsigned char **input, size_t *size,
					int should_swap);
int				pad_input_1024(unsigned char **input, size_t *size,
					int should_swap);
void			debug_input(const unsigned char *input, size_t size);
void			debug_input_int(const unsigned char *input, size_t size);
void			debug_input_hex(const unsigned char *input, size_t size);

uint32_t		rl(uint32_t val, int n);
uint32_t		rr(uint32_t val, int n);
uint64_t		rl64(uint64_t val, int n);
uint64_t		rr64(uint64_t val, int n);
void			swap_uint32(uint32_t *val);
void			swap_bytes(void *to_swap, size_t size, int should_swap);
#endif
