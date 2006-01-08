# $NetBSD: Makefile,v 1.4 2006/01/08 09:57:18 rillig Exp $
#

DISTNAME=		chromium-data-0.9.12
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://www.reptilelabour.com/software/files/chromium/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.reptilelabour.com/software/chromium/
COMMENT=		Data files for chromium scrollshooter

WRKSRC=		${WRKDIR}/Chromium-0.9
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/chromium
	cd ${WRKSRC}/data && ${PAX} -rw -s ',.*/CVS$$,,' -s ',.*/CVS/.*,,' . ${PREFIX}/share/chromium/
	${CHOWN} -R ${GAMEOWN}:${GAMEGRP} ${PREFIX}/share/chromium/

.include "../../mk/bsd.pkg.mk"
