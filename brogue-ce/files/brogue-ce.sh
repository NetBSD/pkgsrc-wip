#!/bin/sh

userdir="${XDG_DATA_HOME:-$HOME/.local/share}/BrogueCE"

mkdir -p "$userdir"
cd "$userdir"

exec @PREFIX@/share/brogue-ce/brogue "$@"
