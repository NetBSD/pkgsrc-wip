# $NetBSD$

DISTNAME=	libretro-beetle-psx-20171012
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

MAINTAINER=	nia.alarie@gmail.com
HOMEPAGE=	https://wiki.libretro.com/index.php?title=Beetle/Mednafen_PSX
COMMENT=	Libretro core based on the Mednafen PlayStation emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	beetle-psx-libretro
GITHUB_TAG=	b6a39e90526f4db5554c680fb6c56e9b2c8ea486

EXTRACT_USING=	bsdtar

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
