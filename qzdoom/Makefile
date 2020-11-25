# $NetBSD$

DISTNAME=	qzdoom-4.4.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=madame-rachelle/}
GITHUB_TAG=	${DISTNAME:S/qzdoom-/g/}

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://qzdoom.drdteam.org/
COMMENT=	Continuation of dpJudas's truecolor software renderer for ZDoom
LICENSE=	gnu-gpl-v3

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
USE_CMAKE=	yes
#CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Debug
CMAKE_ARGS+=	-DNO_OPENAL=OFF
CMAKE_ARGS+=	-DDYN_OPENAL=OFF
CMAKE_ARGS+=	-DNO_OPENMP=ON

WRKSRC=		${WRKDIR}/${DISTNAME:S/-/-g/}

# DOOMWADDIR is intentionally shared with other Doom packages
DOOMWADDIR=		share/doom
INSTALLATION_DIRS+=	share/doc/qzdoom

# Add DOOMWADDIR to search path
SUBST_CLASSES+=		waddir
SUBST_STAGE.waddir=	pre-configure
SUBST_MESSAGE.waddir=	Preparing gameconfigfile.cpp file ...
SUBST_FILES.waddir=	src/gameconfigfile.cpp
SUBST_SED.waddir=	-e 's,PKGSRC_PREFIX,${PREFIX},'
SUBST_SED.waddir+=	-e 's,PKGSRC_DOOMWADDIR,${DOOMWADDIR},'

pre-configure:
	${CP} ${FILESDIR}/INSTALL.pkgsrc ${WRKDIR}

# Keep the gzdoom namespace clean (for a potential future package of gzdoom)
# - Rename binary to qzdoom
# - Rename documentation directory to qzdoom
post-install:
	${INSTALL_DATA} ${WRKDIR}/INSTALL.pkgsrc \
		${DESTDIR}${PREFIX}/share/doc/qzdoom/INSTALL.pkgsrc
	${MV} ${DESTDIR}${PREFIX}/bin/gzdoom ${DESTDIR}${PREFIX}/bin/qzdoom
	${MV} ${DESTDIR}${PREFIX}/share/doc/gzdoom/* \
		${DESTDIR}${PREFIX}/share/doc/qzdoom

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
#.include "../../parallel/openmp/buildlink3.mk"
.include "../../wip/ZMusic/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
