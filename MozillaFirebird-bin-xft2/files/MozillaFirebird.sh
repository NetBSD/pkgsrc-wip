#!@SH@
# $NetBSD: MozillaFirebird.sh,v 1.1.1.1 2003/11/24 05:20:45 grantbeattie Exp $

LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:@PREFIX@/lib/MozillaFirebird-xft2-@PLATFORM@:@PREFIX@/lib"
export LD_LIBRARY_PATH

exec @PREFIX@/lib/MozillaFirebird-xft2-@PLATFORM@/MozillaFirebird "$@"
