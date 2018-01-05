# $NetBSD$

DISTNAME=	libretro-beetle-lynx-20170929
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://docs.libretro.com/library/beetle_handy/
COMMENT=	Libretro core based on the Mednafen Atari Lynx emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	beetle-lynx-libretro
GITHUB_TAG=	0225ca4e2429a82378476f4e4d5f8b303c1a7cb3

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
