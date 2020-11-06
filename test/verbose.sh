#!/usr/bin/env zsh

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
