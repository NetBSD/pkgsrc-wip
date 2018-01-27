# $NetBSD: Makefile,v 1.1 2013/09/02 19:05:24 thomasklausner Exp $

DISTNAME=	sais_source20051111
PKGNAME=	sais-demo-data-20051111
CATEGORIES=	games
MASTER_SITES=	http://zork.net/~nick/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://zork.net/~nick/
COMMENT=	Strange Adventures in Infinite Space engine (SDL port) (demo data files)
LICENSE=	sais-demo-data-license

LICENSE_FILE=	${FILESDIR}/sais-demo-data-license
RESTRICTED=	${LICENSE}

USE_LANGUAGES=		#
INSTALLATION_DIRS=	bin share/doc/sais-demo-data share/sais-demo-data
INSTALLATION_DIRS+=	share/sais-demo-data/gamedata
INSTALLATION_DIRS+=	share/sais-demo-data/graphics
INSTALLATION_DIRS+=	share/sais-demo-data/sounds
INSTALLATION_DIRS+=	share/sais-demo-data/sounds/cards
INSTALLATION_DIRS+=	share/sais-demo-data/sounds/combat
INSTALLATION_DIRS+=	share/sais-demo-data/sounds/music
INSTALLATION_DIRS+=	share/sais-demo-data/sounds/races

do-build:
	sed "s,@PREFIX@,${PREFIX}," files/sais-demo > ${WRKSRC}/sais-demo

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sais-demo ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/demo/manual.txt \
		${DESTDIR}${PREFIX}/share/doc/sais-demo-data
	${INSTALL_DATA} ${WRKSRC}/readme.txt \
		${DESTDIR}${PREFIX}/share/doc/sais-demo-data
	${INSTALL_DATA} ${WRKSRC}/demo/gamedata/* \
		${DESTDIR}${PREFIX}/share/sais-demo-data/gamedata
	${INSTALL_DATA} ${WRKSRC}/demo/graphics/* \
		${DESTDIR}${PREFIX}/share/sais-demo-data/graphics
	${INSTALL_DATA} ${WRKSRC}/demo/sounds/*.* \
		${DESTDIR}${PREFIX}/share/sais-demo-data/sounds
	${INSTALL_DATA} ${WRKSRC}/demo/sounds/cards/* \
		${DESTDIR}${PREFIX}/share/sais-demo-data/sounds/cards
	${INSTALL_DATA} ${WRKSRC}/demo/sounds/combat/* \
		${DESTDIR}${PREFIX}/share/sais-demo-data/sounds/combat
	${INSTALL_DATA} ${WRKSRC}/demo/sounds/music/* \
		${DESTDIR}${PREFIX}/share/sais-demo-data/sounds/music
	${INSTALL_DATA} ${WRKSRC}/demo/sounds/races/* \
		${DESTDIR}${PREFIX}/share/sais-demo-data/sounds/races

.include "../../mk/bsd.pkg.mk"
