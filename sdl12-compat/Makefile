# $NetBSD: Makefile,v 1.6 2023/05/06 19:09:11 ryoon Exp $

DISTNAME=	sdl12-compat-1.2.52
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libsdl-org/}
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/libsdl-org/sdl12-compat
COMMENT=	SDL-1.2 compatibility layer that uses SDL 2.0 behind the scenes
LICENSE=	zlib

USE_CMAKE=	yes

CONFLICTS+=	SDL-[0-9]*

PKGCONFIG_OVERRIDE+=	sdl12_compat.pc.in

SUBST_CLASSES+=			install_name
SUBST_STAGE.install_name=	post-configure
SUBST_FILES.install_name=	CMakeFiles/SDL.dir/link.txt
# With cmake policy CMP0068, @rpath is generated
# SUBST_SED.install_name=		-e 's|@rpath|${PREFIX}/lib|g'
# With cmake policy CMP0068 disabled, no directory is generated
SUBST_SED.install_name=		-e 's|-install_name libSDL-1.2.0.dylib|-install_name ${PREFIX}/lib/libSDL-1.2.0.dylib|g'

CMAKE_ARGS+=	-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON

post-install:
	${RM} ${DESTDIR}${PREFIX}/include/SDL/*.orig

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Darwin"
.  include "../../graphics/MesaLib/buildlink3.mk"
.  include "../../graphics/glu/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
