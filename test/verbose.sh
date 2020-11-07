#!/usr/bin/env zsh

function diff_in() {
	for arg in $@; do
		if [ "$arg" = "diff" ]; then
			return 0
		fi
	done
	return 1
}

function main() {
	CC="clang++"
	CFLAGS="-Wall -Wextra -Werror -std=c++98"

	for arg in $@; do

		if [ "$arg" = "ft" ] || [ "$arg" = "std" ]; then
			CFLAGS+=" -D TESTED_STL=$arg"
		elif [ "$arg" = "db" ]; then
			CFLAGS+=" -fsanitize=address -g3"
		fi

	done

	SRC=(verbose.cpp)

	gpp="$CC $CFLAGS"

	eval "$gpp $SRC" && ./a.out
}

diff_in $*
if [ $? = 1 ]; then
	main $*
else
	ft_file="ft_containers.txt"
	std_file="std_containers.txt"
	main $* ft > $ft_file
	main $* std > $std_file
	diff $std_file $ft_file && echo "No diff :D"
	rm -rf $std_file $ft_file
fi
