# $NetBSD$

DISTNAME=	libretro-mednafen-saturn-20170612
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://wiki.libretro.com/index.php?title=Beetle/Mednafen_Saturn
COMMENT=	Libretro core based on the Mednafen Sega Saturn emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	beetle-saturn-libretro
GITHUB_TAG=	8d70f01370185c9097faa708c5e92fb6d78067ab

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
