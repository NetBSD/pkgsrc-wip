#!/bin/sh
#
# Scan a pkgsrc tree for GO_SRCPATH. To be run from the top-level dir.
#
# To optimize scan time, this only greps for files including go-package.mk.
# If the include is in a Makefile.common, this will break.

: ${MAKE:=bmake}

for i in */*; do
	fgrep -q GO_SRCPATH $i/Makefile 2>/dev/null && {
		printf "$i\t"
		${MAKE} -C $i show-var VARNAME=GO_SRCPATH 2>/dev/null
	}
done
