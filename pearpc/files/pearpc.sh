#!/bin/sh
#
# $NetBSD: pearpc.sh,v 1.1 2004/05/25 06:58:49 xtraeme Exp $

exec @PREFIX@/bin/ppc @PKG_SYSCONFDIR@/ppccfg.conf
exit 0
