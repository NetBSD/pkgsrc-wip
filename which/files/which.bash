#!/bin/bash
unalias -a
unset -- "$@" &> /dev/null
enable -n -- "$@" &> /dev/null
type -p "$@"
