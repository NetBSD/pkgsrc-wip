# $NetBSD$

DISTNAME=	libretro-snes9x2010-20170218
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
HOMEPAGE=	https://wiki.libretro.com/index.php?title=Snes9x_2010
COMMENT=	Libretro core based on the snes9x Super Nintendo emulator
LICENSE=	no-commercial-use

GITHUB_PROJECT=	snes9x2010
GITHUB_TAG=	b2a69de0df1eb39ed362806f9c9633f4544272af

USE_TOOLS=	gmake

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/snes9x2010_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/snes9x2010_libretro.so

.include "../../mk/bsd.pkg.mk"
