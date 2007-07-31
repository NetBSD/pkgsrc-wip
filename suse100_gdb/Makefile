# $NetBSD: Makefile,v 1.3 2007/07/31 21:14:42 jlamwww Exp $

DISTNAME=		suse_gdb-${SUSE_VERSION}
PKGREVISION=		1
CATEGORIES=		emulators
DISTFILES=		gdb-6.3-20.${SUSE_ARCH}.rpm

MAINTAINER=		bsd@cs.ubc.ca
COMMENT=		Linux compatibility package for GDB

EMUL_MODULES.linux=	base

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
