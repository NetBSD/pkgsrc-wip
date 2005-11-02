# $NetBSD: Makefile,v 1.4 2005/11/02 18:00:22 thomasklausner Exp $
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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/microcom ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/microcom/
	${INSTALL_DATA} ${WRKSRC}/index.html ${PREFIX}/share/doc/microcom/

.include "../../mk/bsd.pkg.mk"
