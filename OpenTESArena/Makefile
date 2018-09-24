# $NetBSD$

GITHUB_PROJECT=	OpenTESArena
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-0.8.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=afritz1/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	opentesarena-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/afritz1/OpenTESArena/
COMMENT=	Open-source re-implementation of The Elder Scrolls: Arena
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

SUBST_CLASSES+=			search-path
SUBST_STAGE.search-path=	pre-configure
SUBST_MESSAGE.search-path=	Search for files in PREFIX.
SUBST_FILES.search-path+=	OpenTESArena/src/Utilities/Platform.cpp
SUBST_SED.search-path=		-e 's,@@PKGSRC_DATA_DIR@@,${PREFIX}/share/OpenTESArena/,g'

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/OpenTESArena
INSTALLATION_DIRS+=	share/OpenTESArena/data/text
INSTALLATION_DIRS+=	share/OpenTESArena/options

do-install:
	${INSTALL_GAME} ${WRKSRC}/TESArena ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/OpenTESArena/
	${INSTALL_DATA} ${WRKSRC}/data/*.* ${DESTDIR}${PREFIX}/share/OpenTESArena/data/
	${INSTALL_DATA} ${WRKSRC}/data/text/*.* ${DESTDIR}${PREFIX}/share/OpenTESArena/data/text/
	${INSTALL_DATA} ${WRKSRC}/options/*.* ${DESTDIR}${PREFIX}/share/OpenTESArena/options/

.include "../../audio/libwildmidi/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
