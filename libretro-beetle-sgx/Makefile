# $NetBSD$

DISTNAME=	libretro-beetle-sgx-20170917
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://docs.libretro.com/library/beetle_sgx/
COMMENT=	Libretro core based on the Mednafen SuperGrafx emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	beetle-supergrafx-libretro
GITHUB_TAG=	673a8260521f76467a6967aceb9a0cdbad60c137

EXTRACT_USING+=	bsdtar

USE_TOOLS=	gmake
USE_LANGUAGES=	c c++

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
CFLAGS+=	-DBYTE_ORDER=BIG_ENDIAN
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/mednafen_supergrafx_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mednafen_supergrafx_libretro.so

.include "../../mk/bsd.pkg.mk"
