# $NetBSD$

DISTNAME=	libretro-snes9x-1.55
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=snes9xgit/}

HOMEPAGE=	https://wiki.libretro.com/index.php?title=Snes9x
COMMENT=	Libretro core based on the snes9x Super Nintendo emulator
LICENSE=	no-commercial-use

GITHUB_PROJECT=	snes9x
GITHUB_TAG=	bc8c0d57f954d0505c503d4cb10d6f79bb8445e8

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}/libretro

USE_TOOLS=	gmake
USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/snes9x_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/snes9x_libretro.so

.include "../../mk/bsd.pkg.mk"
