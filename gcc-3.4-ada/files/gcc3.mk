# $NetBSD: gcc3.mk,v 1.2 2004/01/09 23:24:18 johnrshannon Exp $
#
# make configuration file for @PKGNAME@

CC=		@GCC_PREFIX@/bin/cc
CPP=		@GCC_PREFIX@/bin/cpp
ADAC=		@GCC_PREFIX@/bin/gcc
PATH:=		@GCC_PREFIX@/bin:${PATH}
