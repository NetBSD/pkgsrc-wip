# $NetBSD: Makefile,v 1.2 2007/07/30 15:49:11 jlamwww Exp $

DISTNAME=		suse_gdb-${SUSE_VERSION}
PKGREVISION=		1
CATEGORIES=		emulators
DISTFILES=		gdb-6.3-20.${SUSE_ARCH}.rpm

MAINTAINER=		bsd@cs.ubc.ca
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for GDB

EMUL_MODULES.linux=	base

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
