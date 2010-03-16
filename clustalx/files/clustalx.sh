#!/bin/sh
# $NetBSD: clustalx.sh,v 1.1 2010/03/16 15:12:46 brook1 Exp $

LIBEXECDIR=@LIBEXECDIR@
CLUSTALX=${LIBEXECDIR}/clustalx

exec ${CLUSTALX} $*
