# $NetBSD$

DISTNAME=	libretro-mednafen-psx-20170507
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
COMMENT=	Libretro core based on the Mednafen PlayStation emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	beetle-psx-libretro
GITHUB_TAG=	76862abefdde9097561e2b795e75b49247deff17

USE_TOOLS=	gmake

USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/mednafen_psx_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mednafen_psx_libretro.so

.include "../../mk/bsd.pkg.mk"
