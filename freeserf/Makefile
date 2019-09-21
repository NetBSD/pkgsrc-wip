# $NetBSD$

DISTNAME=	freeserf-0.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=freeserf/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jonls.dk/freeserf/
COMMENT=	Settlers 1 (Serf City: Life is Feudal) clone
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++11

# C++11
GCC_REQD+=	4.7

CMAKE_ARGS+=	-DENABLE_TESTS=OFF
CMAKE_ARGS+=	-DFREESERF_VERSION=${PKGVERSION}

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Correcting path to PREFIX.
SUBST_FILES.prefix+=	src/data.cc
SUBST_SED.prefix+=	-e "s,/usr/local,${PREFIX},g"

PYTHON_FOR_BUILD_ONLY=	tool

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/doc/freeserf
INSTALLATION_DIRS+=	share/freeserf
INSTALLATION_DIRS+=	share/pixmaps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/FreeSerf \
	    ${DESTDIR}${PREFIX}/bin/freeserf
	${INSTALL_DATA} ${FILESDIR}/freeserf.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/cmake/icon.png \
	    ${DESTDIR}${PREFIX}/share/pixmaps/freeserf.png
	cd ${WRKSRC} && ${INSTALL_DATA} README.md COPYING \
	    ${DESTDIR}${PREFIX}/share/doc/freeserf

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../audio/libxmp/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
