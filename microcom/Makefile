# $NetBSD: Makefile,v 1.3 2005/04/11 21:14:02 tvierling Exp $
#

DISTNAME=		m102
PKGNAME=		microcom-1.02
CATEGORIES=		wip comms
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
