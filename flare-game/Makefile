# $NetBSD: Makefile,v 1.1 2013/02/08 14:21:57 othyro Exp $
#

DISTNAME=	v0.17.1
PKGNAME=	flare-game-${DISTNAME:S/v//1}
CATEGORIES=	games
MASTER_SITES=	https://github.com/clintbellanger/flare-game/archive/
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://flarerpg.org/
COMMENT=	Fantasy action RPG using the FLARE engine
LICENSE=	gnu-gpl-v3 AND cc-by-sa-v3.0 AND open-font-license AND gnu-gpl-v2

CONFLICTS=	flare-engine-[0-9]*

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

CMAKE_ARGS+=    -DCMAKE_INSTALL_PREFIX:STRING="${DESTDIR}${PREFIX}"
CMAKE_ARGS+=    -DDATADIR:STRING="${PREFIX}/share/flare"

REPLACE_PYTHON=	mods/fantasycore/languages/xgettext.py

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	CMakeLists.txt build/cmake_install.cmake src/Settings.cpp
SUBST_FILES.paths+=	build/CMakeFiles/flare.dir/DependInfo.cmake
SUBST_FILES.paths+=	build/flare.desktop build/CMakeFiles/flare.dir/flags.make
SUBST_FILES.paths+=	build/CMakeCache.txt
SUBST_MESSAGE.paths=	Fixing paths.
SUBST_SED.paths=	-e "s|/usr/local/games|${PREFIX}/bin|g"
SUBST_SED.paths+=	-e "s|/usr/local|${PREFIX}|g"
SUBST_SED.paths+=	-e 's|share/games|share|g'
SUBST_SED.paths+=	-e 's|/games|/bin|1'
SUBST_STAGE.paths=	post-configure

pre-configure:
	cd ${WRKSRC} && ${MKDIR} build

do-configure:
	cd ${WRKSRC}/build && ${SETENV} ${CONFIGURE_ENV} ${CMAKE} ..

do-build:
	cd ${WRKSRC}/build && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}

do-install:
	cd ${WRKSRC}/build && ${SETENV} ${INSTALL_ENV} ${MAKE_PROGRAM} ${INSTALL_TARGET}

.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
