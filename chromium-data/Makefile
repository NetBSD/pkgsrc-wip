# $NetBSD: Makefile,v 1.2 2005/04/11 21:10:29 tvierling Exp $
#

DISTNAME=		chromium-data-0.9.12
CATEGORIES=		wip games
MASTER_SITES=		http://www.reptilelabour.com/software/files/chromium/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.reptilelabour.com/software/chromium/
COMMENT=		Data files for chromium scrollshooter

WRKSRC=		${WRKDIR}/Chromium-0.9
NO_BUILD=#

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/chromium
	${CP} -rf ${WRKSRC}/data/* ${PREFIX}/share/chromium/
	${CHOWN} -R ${GAMEOWN}:${GAMEGRP} ${PREFIX}/share/chromium/
	${CHMOD} -R ${GAMEDATAMODE} ${PREFIX}/share/chromium/

.include "../../mk/bsd.pkg.mk"
