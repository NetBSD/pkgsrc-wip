# $NetBSD$

DISTNAME=	libretro-beetle-saturn-20170808
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

MAINTAINER=	nia.alarie@gmail.com
HOMEPAGE=	https://wiki.libretro.com/index.php?title=Beetle/Mednafen_Saturn
COMMENT=	Libretro core based on the Mednafen Sega Saturn emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	beetle-saturn-libretro
GITHUB_TAG=	682ca8aa92817c76fc7da24c67f45878f9a1aa08

EXTRACT_USING=	bsdtar

USE_TOOLS=	gmake
USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

do-install:
	${INSTALL_LIB} ${WRKSRC}/mednafen_saturn_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mednafen_saturn_libretro.so

.include "../../mk/bsd.pkg.mk"
