# $NetBSD$

DISTNAME=	libretro-beetle-ngp-20171024
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

MAINTAINER=	nia.alarie@gmail.com
HOMEPAGE=	https://docs.libretro.com/library/beetle_neopop/
COMMENT=	Libretro core based on the Mednafen Neo Geo Pocket emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	beetle-ngp-libretro
GITHUB_TAG=	ab5d1d5933134c97d4c04a9a045887bf3bdb5aba

USE_TOOLS=	gmake
USE_LANGUAGES=	c c++

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/mednafen_ngp_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mednafen_ngp_libretro.so

.include "../../mk/bsd.pkg.mk"
