# $NetBSD$

DISTNAME=	libretro-tyrquake-20180222
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	tyrquake
GITHUB_TAG=	9db6a3bedd081b9105d2371550ee8238440f8e87

HOMEPAGE=	https://docs.libretro.com/library/tyrquake/
COMMENT=	Libretro core for the TyrQuake interpreter for Quake and Quakeworld
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/tyrquake_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/tyrquake_libretro.so

.include "../../mk/bsd.pkg.mk"
