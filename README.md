# ft_ssl_md5
42 hashing project

![oops something went wrong, try to check on https://raw.githubusercontent.com/ldedier/ft_ssl_md5/master/resources/md5.gif](https://raw.githubusercontent.com/ldedier/ft_ssl_md5/master/resources/md5.gif)

ft_ssl clone

## supported hashes

* md5
* sha224
* sha256
* sha384
* sha512

## Usage

./ft_ssl  { md5 , sha256 , sha224 , sha384 , sha512 } `[-p]` `[-q]` `[-r]` `[-s string_to_hash]` `[filename]`

* -p:		echo stdin to stdout and append the checksum to stdout
* -q:		quiet mode
* -r:		reverse output format
* -s:		print the sum of the given string

* ./ft_ssl hash -s string
* ./ft_ssl hash filename
