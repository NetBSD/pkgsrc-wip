# $NetBSD$

NP2KAI_REV=	13
DISTNAME=	libretro-np2kai-0.${NP2KAI_REV}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=AZO234/}

HOMEPAGE=	https://github.com/AZO234/NP2kai
COMMENT=	Libretro core based on the Neko Project II PC-9801 emulator
LICENSE=	mit

GITHUB_PROJECT=	NP2kai
GITHUB_TAG=	rev.${NP2KAI_REV}

BUILD_DIRS=	sdl2
MAKE_FILE=	Makefile.libretro

USE_TOOLS=	gmake
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"

# The networking code currently uses non-portable Linux-specific calls.
.if ${OPSYS} != "Linux"
MAKE_FLAGS=	SUPPORT_NET=0
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/sdl2/np2kai_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/np2kai_libretro.so

.include "../../mk/bsd.pkg.mk"
