# $NetBSD$

DISTNAME=	libretro-prosystem-20170124
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
HOMEPAGE=	https://wiki.libretro.com/index.php?title=ProSystem
COMMENT=	Libretro core based on the ProSystem Atari 7800 emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	prosystem-libretro
GITHUB_TAG=	1cf54722a37e30a82a16db2a4fbb5edcbe005c70

USE_TOOLS=	gmake

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/prosystem_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/prosystem_libretro.so

.include "../../mk/bsd.pkg.mk"
