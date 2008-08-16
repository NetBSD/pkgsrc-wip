# $NetBSD: Makefile,v 1.2 2008/08/16 19:31:04 leot1990 Exp $
#

DISTNAME=	fortune-it-1.99
CATEGORIES=	games
MASTER_SITES=	http://www.fortune-it.net/download/ \
		ftp://sunsite.unc.edu/pub/Linux/games/amusements/fortune/

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://www.fortune-it.net/
COMMENT=	Italian fortunes

BUILD_DEPENDS+=	fortune-strfile-[0-9]*:../../games/fortune-strfile

PKG_DESTDIR_SUPPORT=	user-destdir

STRFILE=	${LOCALBASE}/bin/strfile

do-build:
	find ${WRKSRC}/testi/ -type f -exec ${STRFILE} {} \;

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/games/fortune/it
	${INSTALL_DATA} ${WRKSRC}/testi/* \
		${DESTDIR}${PREFIX}/share/games/fortune/it

.include "../../mk/bsd.pkg.mk"
