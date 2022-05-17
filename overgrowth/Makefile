# $NetBSD$

DISTNAME=	overgrowth-0.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=dressupgeekout/}
# 'charlotte-netbsd' branch:
GITHUB_TAG=	a8a20e09108ecfc4921a4b409af537a159982672

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://overgrowth.wolfire.com/
COMMENT=	Overgrowth from Wolfire Games (engine only)
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/overgrowth-${GITHUB_TAG}/Projects
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

# Out-of-tree build is required.
CONFIGURE_DIRS+=	${WRKDIR}/build

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DENABLE_RAD_TELEMETRY=OFF
CMAKE_ARGS+=	-DBUILD_OGDA=OFF
CMAKE_ARGS+=	-DAUX_DATA=${PREFIX}/share/overgrowth
CMAKE_ARG_PATH=	${WRKSRC}

INSTALLATION_DIRS+=	bin

pre-configure:
	${MKDIR} ${WRKDIR}/build

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/build/Overgrowth ${DESTDIR}${PREFIX}/bin/Overgrowth
	${INSTALL_PROGRAM} ${WRKDIR}/build/OvergrowthWorker ${DESTDIR}${PREFIX}/bin/OvergrowthWorker

.include "../../archivers/brotli/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/SDL2_net/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
