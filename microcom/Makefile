# $NetBSD: Makefile,v 1.6 2012/11/25 23:32:28 othyro Exp $
#

DISTNAME=		m102
PKGNAME=		microcom-1.02
CATEGORIES=		comms
MASTER_SITES=		http://microcom.port5.com/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://microcom.port5.com/
COMMENT=		Minicom-like serial terminal emulator with scripting

WRKSRC=		${WRKDIR}/
BUILD_TARGET=	microcom

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/microcom ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/microcom/
	${INSTALL_DATA} ${WRKSRC}/index.html ${DESTDIR}${PREFIX}/share/doc/microcom/

.include "../../mk/bsd.pkg.mk"
