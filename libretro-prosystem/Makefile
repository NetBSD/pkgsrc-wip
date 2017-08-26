# $NetBSD$

DISTNAME=	libretro-prosystem-20170822
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://wiki.libretro.com/index.php?title=ProSystem
COMMENT=	Libretro core based on the ProSystem Atari 7800 emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	prosystem-libretro
GITHUB_TAG=	31d2b8eb55fa078df7440575d7dacfa550a30106

USE_TOOLS=	gmake

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/prosystem_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/prosystem_libretro.so

.include "../../mk/bsd.pkg.mk"
