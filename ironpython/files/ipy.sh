#!/bin/sh
#
# $NetBSD: ipy.sh,v 1.1.1.1 2009/05/12 15:17:03 jihbed Exp $
#

# Fix up LD_LIBRARY_PATH so that /lib is always searched for shared
# libraries.
#
prefix=/usr/pkg

LD_LIBRARY_PATH=/usr/pkg/lib/ironpython; export LD_LIBRARY_PATH

exec $prefix/bin/mono $prefix/lib/ironpython/ipy.exe "$@"
