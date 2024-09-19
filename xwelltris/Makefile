# $NetBSD: Makefile,v 1.5 2012/10/07 20:11:11 asau Exp $
#

DISTNAME=	xwelltris_1.0.1.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/x/xwelltris/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xnc.jinr.ru/xwelltris/
COMMENT=	Tetris like popular game
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	bin share/xwelltris

do-install:
	${INSTALL_GAME} ${WRKSRC}/xwelltris ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/data/*.dat ${WRKSRC}/data/*.gif \
	    ${DESTDIR}${PREFIX}/share/xwelltris
	${INSTALL_GAME_DATA} ${WRKSRC}/data/welltris.scores \
	    ${DESTDIR}${PREFIX}/share/xwelltris

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
