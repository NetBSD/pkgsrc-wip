# $NetBSD: Makefile,v 1.4 2015/01/10 20:53:32 thomasklausner Exp $

PKGNAME=		suse_gdb-${SUSE_VERSION}
PKGREVISION=		1
CATEGORIES=		emulators
DISTFILES=		gdb-6.3-20.${SUSE_ARCH}.rpm

MAINTAINER=		bsd@cs.ubc.ca
COMMENT=		Linux compatibility package for GDB

EMUL_MODULES.linux=	base

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
