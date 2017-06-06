# $NetBSD$

DISTNAME=	libretro-mednafen-psx-20170507
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://wiki.libretro.com/index.php?title=Beetle/Mednafen_PSX
COMMENT=	Libretro core based on the Mednafen PlayStation emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	beetle-psx-libretro
GITHUB_TAG=	76862abefdde9097561e2b795e75b49247deff17

USE_TOOLS=	gmake

USE_LANGUAGES=	c c++

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/mednafen_psx_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mednafen_psx_libretro.so

.include "../../mk/bsd.pkg.mk"
