# $NetBSD$

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	OpenJKDF2-0.9.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=shinyquagsire23/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/shinyquagsire23/OpenJKDF2/
COMMENT=	Cross-platform reimplementation of the Dark Forces 2 game engine
#LICENSE=	# TODO: (see mk/license.mk)

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

.include "../../lang/python/pyversion.mk"
TOOL_DEPENDS+= ${PYPKGPREFIX}-cogapp-[0-9]*:../../devel/py-cogapp

CMAKE_CONFIGURE_ARGS+=	-DPLAT_PKGSRC:BOOL=TRUE
CMAKE_CONFIGURE_ARGS+=	-DPLAT_PKGSRC64:BOOL=FALSE
CMAKE_CONFIGURE_ARGS+=	-DPYVERSSUFFIX=${PYVERSSUFFIX}

.for platform in ${LP64PLATFORMS}
.  if ${MACHINE_PLATFORM:M${platform}}
CMAKE_CONFIGURE_ARGS+=	-DPLAT_PKGSRC64:BOOL=TRUE
.  endif
.endfor

PKGCONFIG_OVERRIDE+=	3rdparty/json/cmake/pkg-config.pc.in

DL_AUTO_VARS=	yes

INSTALLATION_DIRS+=	bin
INSTALL_TARGET=		preinstall

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${CMAKE_BUILD_DIR}/openjkdf2 ${DESTDIR}${PREFIX}/bin

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/freealut/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
