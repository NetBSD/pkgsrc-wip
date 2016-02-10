# $NetBSD: Makefile,v 1.3 2012/09/28 23:21:48 asau Exp $
#

DISTNAME=	fortune-it-1.99
CATEGORIES=	games
MASTER_SITES=	http://www.fortune-it.net/download/ \
		ftp://sunsite.unc.edu/pub/Linux/games/amusements/fortune/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://www.fortune-it.net/
COMMENT=	Italian fortunes

BUILD_DEPENDS+=	fortune-strfile-[0-9]*:../../games/fortune-strfile

STRFILE=	${LOCALBASE}/bin/strfile

do-build:
	find ${WRKSRC}/testi/ -type f -exec ${STRFILE} {} \;

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/games/fortune/it
	${INSTALL_DATA} ${WRKSRC}/testi/* \
		${DESTDIR}${PREFIX}/share/games/fortune/it

.include "../../mk/bsd.pkg.mk"
