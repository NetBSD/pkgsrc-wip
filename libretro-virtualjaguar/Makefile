# $NetBSD$

DISTNAME=	libretro-virtualjaguar-20170218
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://docs.libretro.com/library/virtual_jaguar/
COMMENT=	Libretro core for Atari Jaguar emulation
LICENSE=	gnu-gpl-v3

GITHUB_PROJECT=	virtualjaguar-libretro
GITHUB_TAG=	4f92ba68a64371c97cfd1cc0530d1a4625ec3aef

USE_TOOLS=	gmake

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/virtualjaguar_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/virtualjaguar_libretro.so

.include "../../mk/bsd.pkg.mk"
