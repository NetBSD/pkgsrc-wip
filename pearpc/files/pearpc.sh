#!/bin/sh
#
# $NetBSD: pearpc.sh,v 1.2 2004/06/19 14:57:40 xtraeme Exp $

cd @PREFIX@/share/pearpc && exec ./ppc "$@" @PKG_SYSCONFDIR@/ppccfg.conf
exit 0
