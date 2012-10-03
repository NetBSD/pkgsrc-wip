# $NetBSD: Makefile,v 1.5 2012/10/03 14:11:28 asau Exp $
#

DISTNAME=		m102
PKGNAME=		microcom-1.02
CATEGORIES=		comms
MASTER_SITES=		http://microcom.port5.com/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://microcom.port5.com/
COMMENT=		Minicom-like serial terminal emulator with scripting

WRKSRC=		${WRKDIR}/
BUILD_TARGET=microcom

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/microcom ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/microcom/
	${INSTALL_DATA} ${WRKSRC}/index.html ${DESTDIR}${PREFIX}/share/doc/microcom/

.include "../../mk/bsd.pkg.mk"
