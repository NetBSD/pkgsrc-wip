# $NetBSD$

DISTNAME=	overgrowth-0.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=dressupgeekout/}
# 'charlotte_netbsd_2023-rebased' branch:
GITHUB_TAG=	da1545e3e2215a73720abf39be0325f144690166

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://overgrowth.wolfire.com/
COMMENT=	Game from Wolfire Games (engine only)
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/overgrowth-${GITHUB_TAG}/Projects
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++11

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DENABLE_RAD_TELEMETRY=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_OGDA=OFF
CMAKE_CONFIGURE_ARGS+=	-DAUX_DATA=${PREFIX}/share/overgrowth

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cmake-pkgsrc-build/Overgrowth ${DESTDIR}${PREFIX}/bin/Overgrowth
	${INSTALL_PROGRAM} ${WRKSRC}/cmake-pkgsrc-build/OvergrowthWorker ${DESTDIR}${PREFIX}/bin/OvergrowthWorker

.include "../../devel/cmake/build.mk"
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
