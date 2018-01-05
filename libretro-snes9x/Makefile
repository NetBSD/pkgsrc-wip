# $NetBSD$

DISTNAME=	libretro-snes9x-1.55
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=snes9xgit/}

HOMEPAGE=	https://docs.libretro.com/library/snes9x/
COMMENT=	Libretro core based on the snes9x Super Nintendo emulator
LICENSE=	no-commercial-use

GITHUB_PROJECT=	snes9x

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}
BUILD_DIRS=	libretro

USE_TOOLS=	gmake
USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/libretro/snes9x_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/snes9x_libretro.so

.include "../../mk/bsd.pkg.mk"
