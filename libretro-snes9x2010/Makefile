# $NetBSD$

DISTNAME=	libretro-snes9x2010-20171112
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://docs.libretro.com/library/snes9x_2010/
COMMENT=	Libretro core based on the snes9x Super Nintendo emulator
LICENSE=	no-commercial-use

GITHUB_PROJECT=	snes9x2010
GITHUB_TAG=	cdc2a1f30a08b9e46c14d64de89b250907ec46c7

MAKE_FILE=	Makefile.libretro
USE_TOOLS=	gmake

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/snes9x2010_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/snes9x2010_libretro.so

.include "../../mk/bsd.pkg.mk"
