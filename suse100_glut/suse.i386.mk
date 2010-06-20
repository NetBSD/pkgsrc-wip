# $NetBSD: suse.i386.mk,v 1.1 2010/06/20 13:26:10 marko_schuetz Exp $

# SuSE i386 RPMs; the -devel version is necessary for libGL.so et.al.
# symlinks only.
#
DISTFILES+=	freeglut-2.4.0-4.${SUSE_ARCH}.rpm
DISTFILES+=	freeglut-devel-2.4.0-4.${SUSE_ARCH}.rpm
