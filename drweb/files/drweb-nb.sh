#!@SH@
#
# This file used for start drweb with default path to ini file.
# $NetBSD: drweb-nb.sh,v 1.1.1.1 2003/04/10 18:51:56 jmmv Exp $

exec @PREFIX@/bin/drweb-fbsd -ini:@PKG_SYSCONFDIR@/drweb32.ini "$@"
