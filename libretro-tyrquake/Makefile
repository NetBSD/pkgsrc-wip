# $NetBSD$

DISTNAME=	libretro-tyrquake-20170802
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://docs.libretro.com/library/tyrquake/
COMMENT=	Libretro core for the TyrQuake interpreter for Quake and Quakeworld
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	tyrquake
GITHUB_TAG=	4525ad4dcd58e402f548b3adb8800b9c4b076e40

USE_TOOLS=	gmake

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/tyrquake_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/tyrquake_libretro.so

.include "../../mk/bsd.pkg.mk"
