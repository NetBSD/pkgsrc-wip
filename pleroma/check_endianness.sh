#!/bin/sh

export ELIXIR_ERL_OPTIONS="+fnu"

if [ "$#" -ne 1 ]; then
	echo "Usage: $0 :endianness"
	exit 1
fi

ARG=$1

printf "===> Checking system endianness..."

elixir -e "(System.endianness == $ARG) && System.halt(0) || System.halt(1)"

if test $? -ne 0; then
	echo "mismatch"
	echo
	echo "Elixir is running in a system with a different endianness than the one its"
    echo "source code was compiled in. You'll need to compile this package on the machine"
	echo "with the same endianness ($ARG) or under QEMU. Sadly cross-compilation across"
	echo "systems with different endianness is not supported by Elixir."
	echo
	echo "More information about this issue:"
	echo "https://github.com/elixir-lang/elixir/issues/2785"
	exit 1
else
	echo "ok"
fi
