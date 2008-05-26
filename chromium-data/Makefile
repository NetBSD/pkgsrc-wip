# $NetBSD: Makefile,v 1.5 2008/05/26 13:59:43 tnn2 Exp $
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

USE_TOOLS+=	pax

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/chromium
	cd ${WRKSRC}/data && pax -rw -s ',.*/CVS$$,,' -s ',.*/CVS/.*,,' . ${PREFIX}/share/chromium/
	${CHOWN} -R ${GAMEOWN}:${GAMEGRP} ${PREFIX}/share/chromium/

.include "../../mk/bsd.pkg.mk"
