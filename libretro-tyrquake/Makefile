# $NetBSD$

DISTNAME=	libretro-tyrquake-20170410
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
COMMENT=	Libretro core for the TyrQuake interpreter for Quake and Quakeworld
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	tyrquake
GITHUB_TAG=	1b494ee0ab9b59d79b21dcaeec6b4998c02c8c95

USE_TOOLS=	gmake

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/tyrquake_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/tyrquake_libretro.so

.include "../../mk/bsd.pkg.mk"
