#!@SH@
#
# This file used for start drweb daemon with default path to ini file.
# $NetBSD: drwebd-nb.sh,v 1.1.1.1 2003/04/10 18:51:56 jmmv Exp $

exec @PREFIX@/sbin/drwebd-fbsd -ini:@PKG_SYSCONFDIR@/drweb32.ini "$@"
