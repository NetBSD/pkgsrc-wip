# $NetBSD$

DISTNAME=	libretro-beetle-lynx-20170605
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://wiki.libretro.com/index.php?title=Beetle/Mednafen_LYNX
COMMENT=	Libretro core based on the Mednafen Atari Lynx emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	beetle-lynx-libretro
GITHUB_TAG=	4e321b72c2c3ed0a4dca67317f98c58cb473446e

USE_TOOLS=	gmake
USE_LANGUAGES=	c c++

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/mednafen_lynx_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mednafen_lynx_libretro.so

.include "../../mk/bsd.pkg.mk"
