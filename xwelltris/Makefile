# $NetBSD: Makefile,v 1.4 2012/06/11 09:45:17 leot1990 Exp $
#

DISTNAME=	xwelltris-1.0.1.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	games
MASTER_SITES=	http://xnc.jinr.ru/xwelltris/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xnc.jinr.ru/xwelltris/
COMMENT=	Tetris like popular game

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	bin share/xwelltris

do-install:
	${INSTALL_GAME} ${WRKSRC}/xwelltris ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/xwelltris
	${INSTALL_DATA} ${WRKSRC}/data/*.dat ${WRKSRC}/data/*.gif \
	    ${DESTDIR}${PREFIX}/share/xwelltris
	${INSTALL_GAME_DATA} ${WRKSRC}/data/welltris.scores \
	    ${DESTDIR}${PREFIX}/share/xwelltris

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
