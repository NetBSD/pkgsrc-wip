# $NetBSD$

DISTNAME=	libretro-beetle-psx-20180223
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	beetle-psx-libretro
GITHUB_TAG=	7a7ae882ff2204ac14eeb7ffc3187eb913785fbc

MAINTAINER=	nia.alarie@gmail.com
HOMEPAGE=	https://docs.libretro.com/library/beetle_psx/
COMMENT=	Libretro core based on the Mednafen PlayStation emulator
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	bsdtar

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/mednafen_psx_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mednafen_psx_libretro.so

.include "../../mk/bsd.pkg.mk"
