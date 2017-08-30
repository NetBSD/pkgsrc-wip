# $NetBSD$

DISTNAME=	libretro-beetle-ngp-20170803
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

MAINTAINER=	nia.alarie@gmail.com
HOMEPAGE=	https://wiki.libretro.com/index.php?title=Beetle/Mednafen_NGP
COMMENT=	Libretro core based on the Mednafen Neo Geo Pocket emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	beetle-ngp-libretro
GITHUB_TAG=	daf65fe59eefcbbd6ff164e52ec4b6fd209e3842

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
