# $NetBSD$

DISTNAME=	libretro-mednafen-saturn-20170802
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

MAINTAINER=	nia.alarie@gmail.com
HOMEPAGE=	https://wiki.libretro.com/index.php?title=Beetle/Mednafen_Saturn
COMMENT=	Libretro core based on the Mednafen Sega Saturn emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	beetle-saturn-libretro
GITHUB_TAG=	be3d5e17cfb5774703d4afe555e110e08a634f60

USE_TOOLS=	gmake
USE_LANGUAGES=	c c++
EXTRACT_USING=	bsdtar

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

do-install:
	${INSTALL_LIB} ${WRKSRC}/mednafen_saturn_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mednafen_saturn_libretro.so

.include "../../mk/bsd.pkg.mk"
