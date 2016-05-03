# $NetBSD$

GITHUB_PROJECT=	SDLPoP
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-1.16
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=NagyD/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=NagyD/SDLPoP/}
COMMENT=	Open-source port of Prince of Persia
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/SDLPoP-${PKGVERSION_NOREV}
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

CFLAGS+=	-D PKGSRC_DATA_PATH="\"${PREFIX}/share/sdlpop/\""

INSTALLATION_DIRS+=	bin share/sdlpop share/doc/sdlpop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/prince ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/SDLPoP.ini ${DESTDIR}${PREFIX}/share/sdlpop
	${INSTALL_DATA} ${WRKSRC}/doc/ChangeLog.txt ${DESTDIR}${PREFIX}/share/doc/sdlpop
	${INSTALL_DATA} ${WRKSRC}/doc/Readme.txt ${DESTDIR}${PREFIX}/share/doc/sdlpop
	cd ${WRKSRC} && find data -type d | while read dir; do \
		${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/sdlpop/$$dir; \
	done
	cd ${WRKSRC} && for file in *.DAT; do \
		${INSTALL_DATA} $$file ${DESTDIR}${PREFIX}/share/sdlpop/$$file; \
	done
	cd ${WRKSRC} && find data -type f | while read file; do \
		${INSTALL_DATA} $$file ${DESTDIR}${PREFIX}/share/sdlpop/$$file; \
	done

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
