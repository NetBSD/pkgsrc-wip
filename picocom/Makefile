# $NetBSD: Makefile,v 1.4 2008/12/22 03:58:06 gregschenzel Exp $

DISTNAME=	picocom-1.4
PKGREVISION=	2
CATEGORIES=	comms

MAINTAINER=	inittab@unixdev.net
MASTER_SITES=   http://efault.net/npat/hacks/picocom/dist/

HOMEPAGE=       http://efault.net/npat/hacks/picocom/
COMMENT=        Dumb Terminal Emulator

USE_TOOLS+=             gmake
BUILD_TARGET=		picocom

INSTALLATION_DIRS=      bin ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picocom ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/picocom.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
