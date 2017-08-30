# $NetBSD$

DISTNAME=	libretro-beetle-psx-20170828
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

MAINTAINER=	nia.alarie@gmail.com
HOMEPAGE=	https://wiki.libretro.com/index.php?title=Beetle/Mednafen_PSX
COMMENT=	Libretro core based on the Mednafen PlayStation emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	beetle-psx-libretro
GITHUB_TAG=	5a3093be0fb24dbb1d95303ae615ad4647cb54f6

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
