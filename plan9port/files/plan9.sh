#!/bin/sh

# Define plan9 environment.
PLAN9=@PREFIX@/plan9
PATH="$PATH:$PLAN9/bin"

home=$HOME
user=$USER

# Set rc(1) prompt.
H=`hostname | sed 's/\..*//'`
prompt="$H-;  "

# get rid of ANSI color codes.
#TERM=dumb

# Default font for Plan 9 programs.
#font=${PLAN9}/font/lucm/unicode.9.font
font=${PLAN9}/font/pelm/unicode.8.font

# Preferred plan9 editor.
editor=acme

# Sane text paging.
#MANPAGER='9 p'
#PAGER='col -b'

export \
H\
MANPAGER\
PAGER\
PATH\
PLAN9\
TERM\
editor\
font\
home\
prompt\
user\
