#!/bin/sh

QUEX_PATH=`dirname "$(readlink -f "$0")"`
export QUEX_PATH
"$QUEX_PATH"/quex-exe.py $@
