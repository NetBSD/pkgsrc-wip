# $NetBSD: Makefile,v 1.5 2014/06/18 21:01:42 gregschenzel Exp $

DISTNAME=	picocom-1.7
PKGREVISION=	1
CATEGORIES=	comms

MAINTAINER=	inittab@unixdev.net
MASTER_SITES=   http://picocom.googlecode.com/files/

HOMEPAGE=       https://code.google.com/p/picocom/
COMMENT=        Dumb Terminal Emulator

USE_TOOLS+=             gmake
BUILD_TARGET=		picocom

INSTALLATION_DIRS=      bin ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picocom ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/picocom.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
