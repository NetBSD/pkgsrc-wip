# $NetBSD$

GITHUB_PROJECT=	witchblast
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	v${PKGVERSION_NOREV}
PKGNAME=	${GITHUB_PROJECT}-0.7.5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=Cirrus-Minor/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Cirrus-Minor/witchblast/
COMMENT=	Roguelite dungeon crawler game
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/witchblast-0.7.5
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CXXFLAGS+=	-D WITCHBLAST_DATA_DIR=\"${PREFIX}/${WITCHBLAST_DATA_DIR}/\"

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/witchblast
INSTALLATION_DIRS+=	${WITCHBLAST_DATA_DIR}/data
INSTALLATION_DIRS+=	${WITCHBLAST_DATA_DIR}/media
INSTALLATION_DIRS+=	${WITCHBLAST_DATA_DIR}/media/sound
WITCHBLAST_DATA_DIR=	share/witchblast

do-install:
	${INSTALL_GAME} ${WRKSRC}/Witch_Blast ${DESTDIR}${PREFIX}/bin/witchblast
	${INSTALL_DATA}	${WRKSRC}/readme.txt ${DESTDIR}${PREFIX}/share/doc/witchblast/
	${INSTALL_GAME_DATA} ${WRKSRC}/data/* ${DESTDIR}${PREFIX}/${WITCHBLAST_DATA_DIR}/data/
	${INSTALL_GAME_DATA} ${WRKSRC}/media/*.* ${DESTDIR}${PREFIX}/${WITCHBLAST_DATA_DIR}/media/
	${INSTALL_GAME_DATA} ${WRKSRC}/media/sound/* ${DESTDIR}${PREFIX}/${WITCHBLAST_DATA_DIR}/media/sound/

.include "../../multimedia/sfml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
